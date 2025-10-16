// Copyright © 2025 Connor Hyde
// Implements a pretty basic elevator.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LyraMovingElevator.generated.h"

UCLASS()
class LYRAGAME_API ALyraMovingElevator : public AActor
{
	GENERATED_BODY()


public:	

	UPROPERTY(Category=ElevatorStats, EditAnywhere, BlueprintReadOnly)
	float HeightChange;

	UPROPERTY(Category=ElevatorStats, EditAnywhere, BlueprintReadOnly)
	float Speed; 

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets default values for this actor's properties
	ALyraMovingElevator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private: 
	float initialHeight; 
	float stepHeight;
	float finalHeight;
	UStaticMeshComponent* box;
	bool down;


};
