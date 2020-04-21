// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GoKartMovementComponent.h"
#include "GoKartReplicatedComponent.generated.h"

struct FHermitCubicSpline {
	FVector StartLocation, TargetLocation, StartDerivative, TargetDerivative;
	FVector InterpolateRotation(float LERPRatio) const {
		return FMath::CubicInterp(StartLocation, StartDerivative, TargetLocation, TargetDerivative, LERPRatio);
	}
	FVector InterpolateDerivative(float LERPRatio) const{
		return FMath::CubicInterpDerivative(StartLocation, StartDerivative, TargetLocation, TargetDerivative, LERPRatio);
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARRACING_API UGoKartReplicatedComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGoKartReplicatedComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	TArray<FGoKartMove> UnacknowledgedMoves;

	UFUNCTION(Server, Reliable, WithValidation)
		void Server_SendMove(FGoKartMove Move);

	FGoKartMove GetLastMove();

	void UpdateServerState(const FGoKartMove& Move);
private:

	void ClearAcknowledgedMoves(FGoKartMove LastMove);
	void GetReplicatedState();

	void ClientTick(float DeltaTime);

	void SplineCreation(float VelocityToDerivative);
	void InterpolateVelocity(float LERPRatio, float VelocityToDerivative);
	void InterpolateRotation(float LERPRatio);
	void InterpolateLocation(float LERPRatio);
	

	UFUNCTION()
		void OnRep_ServerState();

	void SimulatedProxy_OnRep_ServerState();
	void AutonomusProxy_OnRep_ServerState();

	FTransform ClientTransform;
	FVector ClientStartVelocity; 
	FHermitCubicSpline Spline;
	UPROPERTY(ReplicatedUsing = OnRep_ServerState)
		FGoKartState ServerState;

	float ClientTimeSinceUpdate;
	float ClientTimeBetweenUpdates;

	UPROPERTY()
	UGoKartMovementComponent* MovementComponent;
	float ClientReplicatedTime;
	FGoKartMove LastMove;

	UPROPERTY(meta = (AllowPrivateAccess = "true"))
	USceneComponent* MeshOffsetRoot;

	UFUNCTION(BlueprintCallable, meta = (AllowPrivateAccess = "true"))
		void SetMeshOffsetRoot(USceneComponent* Root) { MeshOffsetRoot = Root;};

};
