// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKart.generated.h"

UCLASS()
class CARRACING_API AGoKart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGoKart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void CalculateRollingResistance();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	float Mass = 1000; //kg

	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000; //N

	UPROPERTY(EditAnywhere)
	float DragCoefficient = 10; // Air Resistance Coefficient


	UPROPERTY(EditAnywhere)
		float RRCoefficient = 0.1; // Air Resistance Coefficient

	UPROPERTY(EditAnywhere)
	float MaxDegreePerSecond = 90; //Nb of Degree /s to rotate

	FVector Force;
	FVector AirResistance;
	FVector RollingResistance;
	float Throttle;
	float Steeringthrow;

private:
	/** Handle pressing forwards */
	void MoveForward(float Val);
	void MoveRight(float Val);

	float Gravity;
	FVector Velocity; 

	UPROPERTY(ReplicatedUsing= OnRep_ReplicatedTransform)
	FTransform ReplicatedTransform;

	UFUNCTION()
	void OnRep_ReplicatedTransform();


	UFUNCTION(Server, Reliable, WithValidation)
	void Server_MoveRight(float Value);		

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_MoveForward(float Value);

	void SetReplicatedState();
	void GetReplicatedState();

	void CalculateVelocity(float DeltaTime);
	void CalculateAirResistance();
	void ApplyTranslation(float DeltaTime);
	void ApplyRotation(float DeltaTime);
	void ResetVelocity(FHitResult HitResult);
	
};
