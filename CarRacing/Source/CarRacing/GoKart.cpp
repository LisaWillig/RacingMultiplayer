// Fill out your copyright notice in the Description page of Project Settings.


#include "GoKart.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"

#include "GameFrameWork/GameState.h"

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
	
	if (HasAuthority()) {
		NetUpdateFrequency = 1;
	}
}



// Called every frame
void AGoKart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	CurrentMove.DeltaTime = DeltaTime;
	CurrentMove.Time = GetWorld()->GetGameState()->GetServerWorldTimeSeconds();
	Movement.SetMove(CurrentMove);

	if (GetLocalRole() == ROLE_AutonomousProxy) {
		FGoKartMove MoveToSend = Movement.GetMove();
		Movement.SimulateMove(MoveToSend);
		UnacknowledgedMoves.Add(CurrentMove);
		Server_SendMove(MoveToSend);
	}

	//We are server & in control of pawn
	if (GetLocalRole() == ROLE_Authority && IsLocallyControlled()) {
		FGoKartMove MoveToSend = Movement.GetMove();
		Server_SendMove(MoveToSend);
	}

	if (GetLocalRole() != ROLE_Authority && !IsLocallyControlled()) {
		FGoKartMove MoveToSend = Movement.GetMove();
		Movement.SimulateMove(MoveToSend);
	}
}

void AGoKart::OnRep_ServerState() {
	if (!HasAuthority()) {
		GetReplicatedState();
	}
}

void AGoKart::GetReplicatedState() {
	SetActorTransform(ServerState.Transform);
	Movement.SetVelocity(ServerState.Velocity);

	ClearAcknowledgedMoves(ServerState.LastMove);

	for (const FGoKartMove& Move : UnacknowledgedMoves) {
		Movement.SimulateMove(Move);
	}
}

void AGoKart::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AGoKart, ServerState);
}

// Called to bind functionality to input
void AGoKart::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AGoKart::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGoKart::MoveRight);

}

void AGoKart::MoveForward(float Val){
	CurrentMove.Throttle = Val;
}

void AGoKart::MoveRight(float Val){
	CurrentMove.Steeringthrow = Val;
}

void AGoKart::ClearAcknowledgedMoves(FGoKartMove LastMove) {
	TArray<FGoKartMove> NewMoves;
	for (const FGoKartMove& Move : UnacknowledgedMoves) {
		if (Move.Time > LastMove.Time) {
			NewMoves.Add(Move);
		}
	}
	UnacknowledgedMoves = NewMoves;
	
		/*UnacknowledgedMoves.RemoveAll([LastMove](const FGoKartMove& Move)
		{
			return Move.Time < LastMove.Time;
		});
		*/

}
void AGoKart::Server_SendMove_Implementation(FGoKartMove Move){
	Movement.SimulateMove(Move);
	ServerState.LastMove = Move;
	ServerState.Transform = GetActorTransform();
	ServerState.Velocity = Movement.GetVelocity();
}

bool AGoKart::Server_SendMove_Validate(FGoKartMove Move) {
	//TODO: Validate
	return true;
}
