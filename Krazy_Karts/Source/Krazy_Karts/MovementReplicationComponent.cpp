// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementReplicationComponent.h"

#include "GameFramework/Actor.h" 
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UMovementReplicationComponent::UMovementReplicationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SetIsReplicated(true);
}


// Called when the game starts
void UMovementReplicationComponent::BeginPlay()
{
	Super::BeginPlay();
	
	MovementComponent = GetOwner()->FindComponentByClass<UGoKartMovementComponent>();
}

void UMovementReplicationComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UMovementReplicationComponent, ServerState);
}

// Called every frame
void UMovementReplicationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (MovementComponent == nullptr) { return; }

	//	We are the server and in control of the pawn.
	if (GetOwnerRole() == ROLE_Authority && GetOwner()->GetRemoteRole() == ROLE_SimulatedProxy)
	{
		FGoKartMove Move = MovementComponent->CreateMove(DeltaTime);
		Server_SendMove(Move);
	}

	if (GetOwnerRole() == ROLE_AutonomousProxy)
	{
		FGoKartMove Move = MovementComponent->CreateMove(DeltaTime);
		MovementComponent->SimulateMove(Move);

		UnacknowledgeMoves.Add(Move);
		Server_SendMove(Move);
	}

	if (GetOwnerRole() == ROLE_SimulatedProxy)
	{
		MovementComponent->SimulateMove(GetServerState().LastMove);
	}

	UE_LOG(LogTemp, Warning, TEXT("Queue Length: %d"), UnacknowledgeMoves.Num())
}

void UMovementReplicationComponent::OnRep_ServerState()
{
	if (MovementComponent == nullptr) { return; }

	GetOwner()->SetActorTransform(ServerState.Transform);
	MovementComponent->SetVelocity(ServerState.Velocity);

	ClearAcknowledgeMoves(ServerState.LastMove);

	for (const FGoKartMove& Move : UnacknowledgeMoves)
	{
		MovementComponent->SimulateMove(Move);
	}
}

void UMovementReplicationComponent::ClearAcknowledgeMoves(FGoKartMove LastMove)
{
	TArray<FGoKartMove> NewMoves;

	for (const FGoKartMove& Move : UnacknowledgeMoves)
	{
		if (Move.Time > LastMove.Time)
		{
			NewMoves.Add(Move);
		}
	}
	UnacknowledgeMoves = NewMoves;
}

void UMovementReplicationComponent::Server_SendMove_Implementation(FGoKartMove Move)
{
	if (MovementComponent == nullptr) { return; }

	MovementComponent->SimulateMove(Move);

	ServerState.LastMove = Move;
	ServerState.Transform = GetOwner()->GetActorTransform();
	ServerState.Velocity = MovementComponent->GetVelocity();
}

bool UMovementReplicationComponent::Server_SendMove_Validate(FGoKartMove Move)
{
	return true;	//	Make better validation
}

