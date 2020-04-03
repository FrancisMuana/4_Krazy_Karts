// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKart.generated.h"

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

	/** Handle pressing forwards */
	void MoveForward(float Val);

	/** Handle pressing right */
	void MoveRight(float Val);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:
	UPROPERTY(EditAnywhere, Category = "Defaults")
	float Mass = 1000;	//	mass of the car (kg).

	// The force applied to the car when the throttle is fully down (Newton).
	UPROPERTY(EditAnywhere, Category = "Defaults")
	float MaxDrivingForce = 10000;	// 10,000 N / 1,000 kg gives us acceleration of 10

	FVector Velocity;

	float Throttle;
};
