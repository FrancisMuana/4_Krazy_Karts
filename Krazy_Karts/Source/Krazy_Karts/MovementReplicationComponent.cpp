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

	FGoKartMove LastMove = MovementComponent->GetLastMove();

	//	We are the server and in control of the pawn.
	if (GetOwner()->GetRemoteRole() == ROLE_SimulatedProxy)
	{
		UpdateServerState(LastMove);
	}

	if (GetOwnerRole() == ROLE_AutonomousProxy)
	{
		UnacknowledgeMoves.Add(LastMove);
		Server_SendMove(LastMove);
	}

	if (GetOwnerRole() == ROLE_SimulatedProxy)
	{
		ClientTick(DeltaTime);
	}

	UE_LOG(LogTemp, Warning, TEXT("Queue Length: %d"), UnacknowledgeMoves.Num())
}

void UMovementReplicationComponent::UpdateServerState(const FGoKartMove& Move)
{
	ServerState.LastMove = Move;
	ServerState.Transform = GetOwner()->GetActorTransform();
	ServerState.Velocity = MovementComponent->GetVelocity();
}

void UMovementReplicationComponent::ClientTick(float DeltaTime)
{
	ClientTimeSinceUpdate += DeltaTime;

	if (ClientTimeBetweenLastUpdates < KINDA_SMALL_NUMBER) return;

	FVector TargetLocation = ServerState.Transform.GetLocation();
	float LerpRatio = ClientTimeSinceUpdate / ClientTimeBetweenLastUpdates;
	FVector StartLocation = ClientStartLocation;

	FVector NewLocation = FMath::LerpStable(StartLocation, TargetLocation, LerpRatio);

	GetOwner()->SetActorLocation(NewLocation);
}

void UMovementReplicationComponent::OnRep_ServerState()
{
	switch (GetOwnerRole())
	{
	case ROLE_AutonomousProxy:
		AutonomousProxy_OnRep_ServerState();
		break;

	case ROLE_SimulatedProxy:
		SimulatedProxy_OnRep_ServerState();
		break;
	default:
		break;
	}
}

void UMovementReplicationComponent::AutonomousProxy_OnRep_ServerState()
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

void UMovementReplicationComponent::SimulatedProxy_OnRep_ServerState()
{
	ClientTimeBetweenLastUpdates = ClientTimeSinceUpdate;
	ClientTimeSinceUpdate = 0.f;

	ClientStartLocation = GetOwner()->GetActorLocation();
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

	UpdateServerState(Move);
}

bool UMovementReplicationComponent::Server_SendMove_Validate(FGoKartMove Move)
{
	return true;	//	Make better validation
}

