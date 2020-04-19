// Fill out your copyright notice in the Description page of Project Settings.


#include "GoKartMovementComponent.h"
#include "GameFrameWork/GameState.h"

// Sets default values for this component's properties
UGoKartMovementComponent::UGoKartMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGoKartMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	CalculateRollingResistance();

}

void UGoKartMovementComponent::CalculateRollingResistance()
{
	Gravity = -(GetWorld()->GetGravityZ()) / 100;
	RollingResistance = -RRCoefficient * Velocity.GetSafeNormal() * Gravity * Mass;
}

// Called every frame
void UGoKartMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (GetOwnerRole() == ROLE_AutonomousProxy || GetOwner()->GetRemoteRole() == ROLE_SimulatedProxy)
	{
		CurrentMove = CreateMove(DeltaTime);
		SimulateMove(CurrentMove);
	}

}

void UGoKartMovementComponent::SetThrottle(float newThrottle) {
	Throttle = newThrottle;
}

void UGoKartMovementComponent::SetSteeringThrow(float newSteeringThrow) {
	SteeringThrow = newSteeringThrow;
}
FGoKartMove UGoKartMovementComponent::CreateMove(float DeltaTime)
{
	FGoKartMove NewMove;
	NewMove.DeltaTime = DeltaTime;
	NewMove.Steeringthrow = SteeringThrow;
	NewMove.Throttle = Throttle;
	NewMove.Time = GetWorld()->GetGameState()->GetServerWorldTimeSeconds();

	return NewMove;
}

void UGoKartMovementComponent::SimulateMove(FGoKartMove& Move) {
	CalculateVelocity(Move);
	ApplyRotation(Move);
	ApplyTranslation(Move.DeltaTime);
}

void UGoKartMovementComponent::ApplyRotation(FGoKartMove Move)
{
	float RotationAngle = MaxDegreePerSecond * Move.DeltaTime * Move.Steeringthrow;
	FQuat RotationDelta(GetOwner()->GetActorUpVector(), FMath::DegreesToRadians(RotationAngle));
	GetOwner()->AddActorWorldRotation(RotationDelta);
	Velocity = RotationDelta.RotateVector(Velocity);
}

void UGoKartMovementComponent::ApplyTranslation(float DeltaTime) {
	FVector Translation = Velocity * DeltaTime * 100; //*100 to calculate to cm/t
	FHitResult HitResult;
	GetOwner()->AddActorWorldOffset(Translation, true, &HitResult);
	if (HitResult.IsValidBlockingHit()) {
		Velocity = FVector(0, 0, 0);
	}
}

void UGoKartMovementComponent::CalculateAirResistance() {
	AirResistance = -Velocity.SizeSquared() * DragCoefficient * Velocity.GetSafeNormal();
}

void UGoKartMovementComponent::CalculateVelocity(FGoKartMove Move) {
	CalculateAirResistance();
	Force = GetOwner()->GetActorForwardVector() * MaxDrivingForce * Move.Throttle;
	FVector Accelaration = (Force + AirResistance + RollingResistance) / Mass;
	Velocity = Velocity + Accelaration * Move.DeltaTime;
}


FVector UGoKartMovementComponent::GetVelocity() {
	return Velocity;
}

void UGoKartMovementComponent::SetVelocity(FVector NewVelocity) {
	Velocity = NewVelocity;
}

void UGoKartMovementComponent::SetMove(FGoKartMove Move) {
	CurrentMove = Move;
}

FGoKartMove UGoKartMovementComponent::GetMove() {
	return CurrentMove;
}