// Fill out your copyright notice in the Description page of Project Settings.


#include "GoKart.h"

#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h" 
#include "Net/UnrealNetwork.h"

// Sets default values
AGoKart::AGoKart()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts or when spawned
void AGoKart::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGoKart::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AGoKart, ReplicatedLocation);
	DOREPLIFETIME(AGoKart, ReplicatedRotation);
}

FString GetEnumText(ENetRole Role)
{	
	switch (Role)
	{
	case ROLE_None:
		return "None";
	case ROLE_Authority:
		return "Authority";		
	case ROLE_AutonomousProxy:
		return "AutonomousProxy";
	case ROLE_SimulatedProxy:
		return "SimulatedProxy";
	default:
		return "Error";
	}
}

// Called every frame
void AGoKart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Force = GetActorForwardVector() * MaxDrivingForce * Throttle;

	Force += GetAirResistance();
	Force += GetRollingResistance();

	FVector Acceleration = Force / Mass;	

	Velocity = Velocity + Acceleration * DeltaTime;	

	ApplyRotation(DeltaTime);

	UpdateLocationFromVelocity(DeltaTime);	

	if (HasAuthority())
	{
		ReplicatedLocation = GetActorLocation();
		ReplicatedRotation = GetActorRotation();
	}
	else
	{
		SetActorLocation(ReplicatedLocation);
		SetActorRotation(ReplicatedRotation);
	}

	DrawDebugString(GetWorld(), FVector(0, 0, 100), GetEnumText(Role), this, FColor::Blue, DeltaTime);
}

FVector AGoKart::GetAirResistance()
{
	//	AirResistance = -Speed² * DragCoefficient
	return -Velocity.GetSafeNormal() * Velocity.SizeSquared() * DragCoefficient;
}

FVector AGoKart::GetRollingResistance()
{	//	100 because cm convert to m
	float AccelerationDueToGravity = -GetWorld()->GetGravityZ() / 100;
	float NormalForce = Mass * AccelerationDueToGravity;
	//	RollingResistance = RRCoefficient * NormalForce
	return -Velocity.GetSafeNormal() * RollingResistanceCoefficient * NormalForce;
}

void AGoKart::ApplyRotation(float DeltaTime)
{
	//	if the velocity is a positive number DeltaLocation is '+'. if it's negative, deltalocation becomes '-'
	//	This dotproduct is necessary for the turning of the car in reverse to be correct.
	float DeltaLocation = FVector::DotProduct(GetActorForwardVector(), Velocity) * DeltaTime;
	//	TurningCircle: dtheta = dx / r
	float RotationAngle = DeltaLocation / MinTurningRadius * SteeringThrow;

	FQuat RotationDelta(GetActorUpVector(), RotationAngle);
	//	this is necessary so the forward vector depends on where the car is facing
	Velocity = RotationDelta.RotateVector(Velocity);

	AddActorWorldRotation(RotationDelta);	// turn the car
}

void AGoKart::UpdateLocationFromVelocity(float DeltaTime)
{		//	'100' converts from UE cm to m
	FVector Translation = Velocity * 100 * DeltaTime;	//	dx = v * dt

	FHitResult Hit;
	AddActorWorldOffset(Translation, true, &Hit);

	if (Hit.IsValidBlockingHit())	// If hit something, stop
	{
		Velocity = FVector::ZeroVector;
	}
}

// Called to bind functionality to input
void AGoKart::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGoKart::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGoKart::MoveRight);
}

void AGoKart::MoveForward(float Val)
{
	Throttle = Val;
	Server_MoveForward(Val);
}

void AGoKart::MoveRight(float Val)
{
	SteeringThrow = Val;
	Server_MoveRight(Val);
}

void AGoKart::Server_MoveForward_Implementation(float Val)
{
	Throttle = Val;
}

bool AGoKart::Server_MoveForward_Validate(float Val)
{	
	return FMath::Abs(Val) <= 1;
}

void AGoKart::Server_MoveRight_Implementation(float Val)
{
	SteeringThrow = Val;
}

bool AGoKart::Server_MoveRight_Validate(float Val)
{	
	return FMath::Abs(Val) <= 1;
}



