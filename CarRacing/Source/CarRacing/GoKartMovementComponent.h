// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GoKartMovementComponent.generated.h"


USTRUCT()
struct FGoKartMove {
	GENERATED_USTRUCT_BODY()

		UPROPERTY()
		float Throttle;

	UPROPERTY()
		float Steeringthrow;

	UPROPERTY()
		float DeltaTime;

	UPROPERTY()
		float Time;
};

USTRUCT()
struct FGoKartState {
	GENERATED_USTRUCT_BODY()

		UPROPERTY()
		FGoKartMove LastMove;

	UPROPERTY()
		FVector Velocity;

	UPROPERTY()
		FTransform Transform;
};


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
	
	void SetThrottle(float newThrottle);

	void SetSteeringThrow(float newSteeringThrow);
private:
	
	void CalculateRollingResistance();
	void CalculateVelocity(FGoKartMove Move);
	void CalculateAirResistance();
	void ApplyTranslation(float DeltaTime);
	void ApplyRotation(FGoKartMove Move);
	FGoKartMove CreateMove(float DeltaTime);

	FVector Velocity;
	float Gravity;
	

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

	float Throttle;
	float SteeringThrow;

	FVector Force;
	FVector AirResistance;
	FVector RollingResistance;
	FGoKartMove CurrentMove;
};
