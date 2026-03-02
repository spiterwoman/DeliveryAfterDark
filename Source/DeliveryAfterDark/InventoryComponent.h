#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DELIVERYAFTERDARK_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventoryComponent();

    // The only function the Blueprint needs to call
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool DeliverPackage();

    // Simple getter for the UI to ask "How many left?"
    UFUNCTION(BlueprintPure, Category = "Inventory")
    int32 GetPackageCount() const;

private:
    static constexpr int32 MAX_SLOTS = 4;
    TArray<bool> SlotOccupied;
};