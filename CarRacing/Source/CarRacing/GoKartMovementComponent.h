// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GoKart.h"
#include "GoKartMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARRACING_API UGoKartMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGoKartMovementComponent();

	FVector GetVelocity();
	void SetVelocity(FVector NewVelocity);

	void SetMove(FGoKartMove Move);
	FGoKartMove GetMove();

	void SimulateMove(FGoKartMove& Move);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	
	void CalculateRollingResistance();
	void CalculateVelocity(FGoKartMove Move);
	void CalculateAirResistance();
	void ApplyTranslation(float DeltaTime);
	void ApplyRotation(FGoKartMove Move);

	//UPROPERTY()
	FGoKartMove CurrentMove;

	float Gravity;
	FVector Velocity;

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
};
