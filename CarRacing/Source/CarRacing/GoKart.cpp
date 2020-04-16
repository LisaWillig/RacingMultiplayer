// Fill out your copyright notice in the Description page of Project Settings.


#include "GoKart.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"

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

	
}

void AGoKart::CalculateRollingResistance()
{
	Gravity = -(GetWorld()->GetGravityZ()) / 100;
	RollingResistance = - RRCoefficient * Velocity.GetSafeNormal()* Gravity * Mass;
}

// Called every frame
void AGoKart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CalculateRollingResistance();
	CalculateVelocity(DeltaTime);
	ApplyRotation(DeltaTime);
	ApplyTranslation(DeltaTime);	
}

void AGoKart::ApplyRotation(float DeltaTime)
{
	float RotationAngle = MaxDegreePerSecond * DeltaTime * Steeringthrow;
	FQuat RotationDelta(GetActorUpVector(), FMath::DegreesToRadians(RotationAngle));
	AddActorWorldRotation(RotationDelta);
	Velocity = RotationDelta.RotateVector(Velocity);
}

void AGoKart::ApplyTranslation(float DeltaTime) {
	FVector Translation = Velocity * DeltaTime * 100; //*100 to calculate to cm/t
	FHitResult HitResult;
	AddActorWorldOffset(Translation, true, &HitResult);
	ResetVelocity(HitResult);
}

void AGoKart::ResetVelocity(FHitResult HitResult) {
	if (HitResult.IsValidBlockingHit()) {
		Velocity = FVector(0, 0, 0);
	}
}

void AGoKart::CalculateAirResistance() {
	AirResistance = - Velocity.SizeSquared() * DragCoefficient * Velocity.GetSafeNormal();
}

void AGoKart::CalculateVelocity(float DeltaTime) {
	CalculateAirResistance();
	Force = GetActorForwardVector() * MaxDrivingForce * Throttle;
	FVector Accelaration = (Force + AirResistance + RollingResistance) / Mass;
	Velocity = Velocity + Accelaration * DeltaTime;
}
// Called to bind functionality to input
void AGoKart::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AGoKart::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGoKart::MoveRight);

}

void AGoKart::MoveForward(float Val)
{
	Throttle = Val;
}

void AGoKart::MoveRight(float Val)
{
	Steeringthrow = Val;
}