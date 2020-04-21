// Fill out your copyright notice in the Description page of Project Settings.


#include "GoKartReplicatedComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFrameWork/GameState.h"

// Sets default values for this component's properties
UGoKartReplicatedComponent::UGoKartReplicatedComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SetIsReplicated(true);
}


// Called when the game starts
void UGoKartReplicatedComponent::BeginPlay()
{
	Super::BeginPlay();
	MovementComponent = GetOwner()->FindComponentByClass<UGoKartMovementComponent>();
}


// Called every frame
void UGoKartReplicatedComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (MovementComponent == nullptr) return;
	LastMove = MovementComponent->GetMove();

	 if (GetOwnerRole() == ROLE_AutonomousProxy){
		 UnacknowledgedMoves.Add(LastMove);
		 Server_SendMove(LastMove);
	 }

	if (GetOwner()->HasLocalNetOwner()){
		UpdateServerState(LastMove);
	}

	 if (GetOwnerRole() == ROLE_SimulatedProxy) {
		 ClientTick(DeltaTime);
	 }
}

void UGoKartReplicatedComponent::ClientTick(float DeltaTime) {
	ClientTimeSinceUpdate += DeltaTime;

	if (ClientTimeBetweenUpdates < KINDA_SMALL_NUMBER) return;
	if (MovementComponent == nullptr) return;

	float LERPRatio = ClientTimeSinceUpdate / ClientTimeBetweenUpdates;
	float VelocityToDerivative = ClientTimeBetweenUpdates * 100;

	SplineCreation(VelocityToDerivative);

	InterpolateLocation(LERPRatio);
	InterpolateRotation(LERPRatio);
	InterpolateVelocity(LERPRatio, VelocityToDerivative);
}

void UGoKartReplicatedComponent::SplineCreation(float VelocityToDerivative)
{
	Spline.TargetLocation = ServerState.Transform.GetLocation();
	Spline.StartLocation = ClientTransform.GetLocation();
	Spline.StartDerivative = ClientStartVelocity * VelocityToDerivative;
	Spline.TargetDerivative = ServerState.Velocity * VelocityToDerivative;
}

void UGoKartReplicatedComponent::InterpolateLocation(float LERPRatio)
{
	FVector NextLocation = Spline.InterpolateRotation(LERPRatio);
	GetOwner()->SetActorLocation(NextLocation);
}

void UGoKartReplicatedComponent::InterpolateRotation(float LERPRatio)
{
	FQuat TargetRotation = ServerState.Transform.GetRotation();
	FQuat StartRotation = ClientTransform.GetRotation();
	FQuat NextRotation = FQuat::Slerp(StartRotation, TargetRotation, LERPRatio);
	GetOwner()->SetActorRotation(NextRotation);
}

void UGoKartReplicatedComponent::InterpolateVelocity(float LERPRatio, float VelocityToDerivative)
{
	FVector NextDerivative = Spline.InterpolateDerivative(LERPRatio);
	FVector NextVelocity = NextDerivative / VelocityToDerivative;
	MovementComponent->SetVelocity(NextVelocity);
}

void UGoKartReplicatedComponent::UpdateServerState(const FGoKartMove& Move)
{
	ServerState.LastMove = Move;
	ServerState.Transform = GetOwner()->GetActorTransform();
	if (MovementComponent == nullptr) return;
	ServerState.Velocity = MovementComponent->GetVelocity();
}

FGoKartMove UGoKartReplicatedComponent::GetLastMove() {return LastMove;}

void UGoKartReplicatedComponent::GetReplicatedState() {
	GetOwner()->SetActorTransform(ServerState.Transform);
	if (MovementComponent != nullptr) {
		MovementComponent->SetVelocity(ServerState.Velocity);
		}

	ClearAcknowledgedMoves(ServerState.LastMove);

	for (FGoKartMove& Move : UnacknowledgedMoves) {
		MovementComponent->SimulateMove(Move);
	}
}

void UGoKartReplicatedComponent::OnRep_ServerState() {
	switch (GetOwnerRole()) {
	case ROLE_AutonomousProxy:
		AutonomusProxy_OnRep_ServerState();
		break;
	case ROLE_SimulatedProxy:
		SimulatedProxy_OnRep_ServerState();
		break;
	default:
		break;
	}
}

void UGoKartReplicatedComponent::SimulatedProxy_OnRep_ServerState() {
	ClientTimeBetweenUpdates = ClientTimeSinceUpdate;
	ClientTimeSinceUpdate = 0;
	ClientTransform = GetOwner()->GetActorTransform();
	if (MovementComponent == nullptr) return;
	ClientStartVelocity = MovementComponent->GetVelocity();
}
void UGoKartReplicatedComponent::AutonomusProxy_OnRep_ServerState() {

	GetReplicatedState();
}

void UGoKartReplicatedComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UGoKartReplicatedComponent, ServerState);
}

void UGoKartReplicatedComponent::ClearAcknowledgedMoves(FGoKartMove Move) {
	TArray<FGoKartMove> NewMoves;
	for (const FGoKartMove& Move : UnacknowledgedMoves) {
		if (Move.Time > Move.Time) {
			NewMoves.Add(Move);
		}
	}
	UnacknowledgedMoves = NewMoves;
}

void UGoKartReplicatedComponent::Server_SendMove_Implementation(FGoKartMove Move) {
	if (MovementComponent == nullptr) return;

	MovementComponent->SimulateMove(Move);
	ClientReplicatedTime += Move.DeltaTime;
	UpdateServerState(Move);
}

bool UGoKartReplicatedComponent::Server_SendMove_Validate(FGoKartMove Move) {

	float proposedTime = ClientReplicatedTime + Move.DeltaTime;
	bool ClientRunningAhead = proposedTime > GetWorld()->TimeSeconds;
	if (ClientRunningAhead) {
		UE_LOG(LogTemp, Error, TEXT("Client running to fast"))
		return false;
	}
	if (!Move.IsValid()) {
		UE_LOG(LogTemp, Error, TEXT("Move is not valid: Throttle or SteeringThrow too high"))
		return false;
	}
	return true;
}
