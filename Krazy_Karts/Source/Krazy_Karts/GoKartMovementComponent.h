// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GoKartMovementComponent.generated.h"

USTRUCT()
struct FGoKartMove
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
		float Throttle;
	UPROPERTY()
		float SteeringThrow;

	UPROPERTY()
		float DeltaTime;
	UPROPERTY()
		float Time;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KRAZY_KARTS_API UGoKartMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGoKartMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SimulateMove(const FGoKartMove& Move);
	FGoKartMove CreateMove(float DeltaTime);

	FVector GetVelocity() { return Velocity; };
	void SetVelocity(FVector Val) { Velocity = Val; };
	void SetThrottle(float Val) { Throttle = Val; };
	void SetSteeringThrow(float Val) { SteeringThrow = Val; };

private:
	FVector GetAirResistance();

	FVector GetRollingResistance();

	void ApplyRotation(float DeltaTime, float steeringThrow);

	void UpdateLocationFromVelocity(float DeltaTime);

	UPROPERTY(EditAnywhere, Category = "Defaults")
	float Mass = 1000;	//	mass of the car (kg).

	// The force applied to the car when the throttle is fully down (Newton).
	UPROPERTY(EditAnywhere, Category = "Defaults")
	float MaxDrivingForce = 10000;	// 10,000 N / 1,000 kg gives us acceleration of 10

	UPROPERTY(EditAnywhere, Category = "Defaults")
	float MinTurningRadius = 10; // minimum radius of the car turning circle in meters

	UPROPERTY(EditAnywhere, Category = "Defaults")
	float DragCoefficient = 16;	//	Higher means more drag

	UPROPERTY(EditAnywhere, Category = "Defaults")
	float RollingResistanceCoefficient = 0.015;	//	Higher means more rolling resistance

	FVector Velocity;

	float Throttle;
	float SteeringThrow;
};
