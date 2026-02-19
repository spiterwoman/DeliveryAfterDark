// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"
#include "Perception/AIPerceptionTypes.h"

class UAIPerceptionComponent;
class UAISenseConfig_Sight;

/**
 * 
 */
UCLASS()
class DELIVERYAFTERDARK_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyAIController();

protected:
	virtual void OnPossess(APawn* InPawn) override;

private:
	UPROPERTY();
	UAIPerceptionComponent* PerceptionComp;

	UPROPERTY()
	UAISenseConfig_Sight* SightConfig;

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

public:
	// Tunable properties for sight configuration
	UPROPERTY(EditAnyWhere, Category = "Perception")
	float SightRadius = 1800.f;

	UPROPERTY(EditAnywhere, Category = "Perception")
	float LoseSightRadius = 2200.f;

	UPROPERTY(EditAnywhere, Category = "Perception")
	float PeripheralVisionDegrees = 80.f;

	UPROPERTY(EditAnywhere, Category = "Perception")
	float SightMaxAge = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float ChaseAcceptanceRadius = 100.f;
};
