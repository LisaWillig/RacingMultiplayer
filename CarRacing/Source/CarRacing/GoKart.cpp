// Fill out your copyright notice in the Description page of Project Settings.


#include "GoKart.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"

#include "DrawDebugHelpers.h"

// Sets default values
AGoKart::AGoKart()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
	bReplicateMovement = false;
	MovementComponent = CreateDefaultSubobject<UGoKartMovementComponent>(TEXT("MovementComponent"));
	ReplicatingComponent = CreateDefaultSubobject<UGoKartReplicatedComponent>(TEXT("ReplicatingComponent"));
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
	DrawDebugString(GetWorld(), FVector(0, 0, 100), UEnum::GetValueAsString(GetLocalRole()), this, FColor::White, DeltaTime);
	DrawDebugString(GetWorld(), FVector(0, 0, 125), UEnum::GetValueAsString(GetRemoteRole()), this, FColor::Green, DeltaTime);
}

// Called to bind functionality to input
void AGoKart::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AGoKart::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGoKart::MoveRight);
	
}

void AGoKart::MoveForward(float Val){
	if (MovementComponent == nullptr) return;
	MovementComponent->SetThrottle(Val);
}

void AGoKart::MoveRight(float Val){
	if (MovementComponent == nullptr) return;
	MovementComponent->SetSteeringThrow(Val);
}


