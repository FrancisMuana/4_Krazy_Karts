// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKart.generated.h"

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

USTRUCT()
struct FGoKartState
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FVector Velocity;

	UPROPERTY()
	FTransform Transform;

	UPROPERTY()
	FGoKartMove LastMove;
};

UCLASS()
class KRAZY_KARTS_API AGoKart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGoKart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveForward(float Val);
	void MoveRight(float Val);

	/** Handle pressing forwards */
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SendMove(FGoKartMove Move);	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:
	void SimulateMove(FGoKartMove Move);

	FGoKartMove CreateMove(float DeltaTime);
	void ClearAcknowledgeMoves(FGoKartMove LastMove);

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

	UPROPERTY(ReplicatedUsing = OnRep_ServerState)
	FGoKartState ServerState;	

	FVector Velocity;

	UFUNCTION()
	void OnRep_ServerState();	
	
	float Throttle;
	float SteeringThrow;

	TArray<FGoKartMove> UnacknowledgeMoves;
};
