#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HeatComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DELIVERYAFTERDARK_API UHeatComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UHeatComponent();

    UFUNCTION(BlueprintCallable, Category = "Heat")
    void AddHeat(int32 Amount);

    UFUNCTION(BlueprintCallable, Category = "Heat")
    void DecreaseHeat(int32 Amount);

    UFUNCTION(BlueprintPure, Category = "Heat")
    int32 GetHeat() const;

    UFUNCTION(BlueprintPure, Category = "Heat")
    bool IsMaxHeat() const;

private:
    UPROPERTY();
    int32 CurrentHeat;
};
