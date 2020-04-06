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

	MovementComponent = CreateDefaultSubobject<UGoKartMovementComponent>(TEXT("MovementComponent"));
}

// Called when the game starts or when spawned
void AGoKart::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		NetUpdateFrequency = 1;
	}	
}

void AGoKart::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AGoKart, ServerState);	
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

	if (MovementComponent == nullptr) { return; }

	//	We are the server and in control of the pawn.
	if (Role == ROLE_Authority && IsLocallyControlled())
	{	
		FGoKartMove Move = MovementComponent->CreateMove(DeltaTime);
		Server_SendMove(Move);
	}		

	if (Role == ROLE_AutonomousProxy)
	{		
		FGoKartMove Move = MovementComponent->CreateMove(DeltaTime);
		MovementComponent->SimulateMove(Move);

		UnacknowledgeMoves.Add(Move);
		Server_SendMove(Move);
	}

	if (Role == ROLE_SimulatedProxy)
	{		
		MovementComponent->SimulateMove(ServerState.LastMove);
	}

	UE_LOG(LogTemp, Warning, TEXT("Queue Length: %d"), UnacknowledgeMoves.Num())
	DrawDebugString(GetWorld(), FVector(0, 0, 100), GetEnumText(Role), this, FColor::Blue, DeltaTime);
}

void AGoKart::OnRep_ServerState()
{
	if (MovementComponent == nullptr) { return; }

	SetActorTransform(ServerState.Transform);
	MovementComponent->SetVelocity(ServerState.Velocity);

	ClearAcknowledgeMoves(ServerState.LastMove);

	for (const FGoKartMove& Move : UnacknowledgeMoves)
	{
		MovementComponent->SimulateMove(Move);
	}
}

void AGoKart::ClearAcknowledgeMoves(FGoKartMove LastMove)
{
	TArray<FGoKartMove> NewMoves;

	for (const FGoKartMove& Move: UnacknowledgeMoves)
	{
		if (Move.Time > LastMove.Time)
		{
			NewMoves.Add(Move);
		}
	}
	UnacknowledgeMoves = NewMoves;
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
	if (MovementComponent == nullptr) { return; }

	MovementComponent->SetThrottle(Val);
}

void AGoKart::MoveRight(float Val)
{
	if (MovementComponent == nullptr) { return; }

	MovementComponent->SetSteeringThrow(Val);
}

void AGoKart::Server_SendMove_Implementation(FGoKartMove Move)
{
	if (MovementComponent == nullptr) { return; }

	MovementComponent->SimulateMove(Move);

	ServerState.LastMove = Move;
	ServerState.Transform = GetActorTransform();
	ServerState.Velocity = MovementComponent->GetVelocity();
}

bool AGoKart::Server_SendMove_Validate(FGoKartMove Move)
{	
	return true;	//	Make better validation
}