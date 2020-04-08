// Fill out your copyright notice in the Description page of Project Settings.


#include "GoKartMovementComponent.h"

#include "Engine/World.h" 
#include "GameFramework/GameStateBase.h" 

// Sets default values for this component's properties
UGoKartMovementComponent::UGoKartMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGoKartMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGoKartMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetOwnerRole() == ROLE_AutonomousProxy || GetOwner()->GetRemoteRole() == ROLE_SimulatedProxy)
	{
		LastMove = CreateMove(DeltaTime);
		SimulateMove(LastMove);
	}	
}

void UGoKartMovementComponent::SimulateMove(const FGoKartMove& Move)
{
	FVector Force = GetOwner()->GetActorForwardVector() * MaxDrivingForce * Move.Throttle;

	Force += GetAirResistance();
	Force += GetRollingResistance();

	FVector Acceleration = Force / Mass;

	Velocity = Velocity + Acceleration * Move.DeltaTime;

	ApplyRotation(Move.DeltaTime, Move.SteeringThrow);

	UpdateLocationFromVelocity(Move.DeltaTime);
}

FGoKartMove UGoKartMovementComponent::CreateMove(float DeltaTime)
{
	FGoKartMove Move;
	Move.DeltaTime = DeltaTime;
	Move.SteeringThrow = SteeringThrow;
	Move.Throttle = Throttle;
	Move.Time = GetWorld()->GetGameState()->GetServerWorldTimeSeconds();

	return Move;
}

FVector UGoKartMovementComponent::GetAirResistance()
{
	//	AirResistance = -Speed² * DragCoefficient
	return -Velocity.GetSafeNormal() * Velocity.SizeSquared() * DragCoefficient;
}

FVector UGoKartMovementComponent::GetRollingResistance()
{	//	100 because cm convert to m
	float AccelerationDueToGravity = -GetWorld()->GetGravityZ() / 100;
	float NormalForce = Mass * AccelerationDueToGravity;
	//	RollingResistance = RRCoefficient * NormalForce
	return -Velocity.GetSafeNormal() * RollingResistanceCoefficient * NormalForce;
}

void UGoKartMovementComponent::ApplyRotation(float DeltaTime, float steeringThrow)
{
	//	if the velocity is a positive number DeltaLocation is '+'. if it's negative, deltalocation becomes '-'
	//	This dotproduct is necessary for the turning of the car in reverse to be correct.
	float DeltaLocation = FVector::DotProduct(GetOwner()->GetActorForwardVector(), Velocity) * DeltaTime;
	//	TurningCircle: dtheta = dx / r
	float RotationAngle = DeltaLocation / MinTurningRadius * steeringThrow;

	FQuat RotationDelta(GetOwner()->GetActorUpVector(), RotationAngle);
	//	this is necessary so the forward vector depends on where the car is facing
	Velocity = RotationDelta.RotateVector(Velocity);

	GetOwner()->AddActorWorldRotation(RotationDelta);	// turn the car
}

void UGoKartMovementComponent::UpdateLocationFromVelocity(float DeltaTime)
{		//	'100' converts from UE cm to m
	FVector Translation = Velocity * 100 * DeltaTime;	//	dx = v * dt

	FHitResult Hit;
	GetOwner()->AddActorWorldOffset(Translation, true, &Hit);

	if (Hit.IsValidBlockingHit())	// If hit something, stop
	{
		Velocity = FVector::ZeroVector;
	}
}
