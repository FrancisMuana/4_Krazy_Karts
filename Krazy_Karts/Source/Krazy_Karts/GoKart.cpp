// Fill out your copyright notice in the Description page of Project Settings.


#include "GoKart.h"

#include "Components/InputComponent.h"
#include "Engine/World.h"

// Sets default values
AGoKart::AGoKart()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoKart::BeginPlay()
{
	Super::BeginPlay();
	
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
}

FVector AGoKart::GetAirResistance()
{
	//	AirResistance = -Speed� * DragCoefficient
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
	float RotationAngle = MaxDegreesPerSecond * DeltaTime * SteeringThrow;
	FQuat RotationDelta(GetActorUpVector(), FMath::DegreesToRadians(RotationAngle));

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

void AGoKart::MoveForward(float Val)
{
	Throttle = Val;
}

void AGoKart::MoveRight(float Val)
{
	SteeringThrow = Val;
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

