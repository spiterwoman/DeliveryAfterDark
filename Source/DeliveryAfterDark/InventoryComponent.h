#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FOnInventoryChanged,
    const TArray<bool>&, SlotOccupied,
    int32, PackageCount
);


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DELIVERYAFTERDARK_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventoryComponent();

    static constexpr int32 MAX_SLOTS = 4;


    /** Attempt to add a package to the next empty slot.
     *  @return true  if a slot was available and the package was added.
     *  @return false if inventory is already full. */
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool PickupPackage();

    /** Attempt to remove one package (uses the last occupied slot).
     *  @return true  if a package was present and has been removed.
     *  @return false if inventory is empty. */
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool DeliverPackage();

    /** Current number of packages being carried. */
    UFUNCTION(BlueprintPure, Category = "Inventory")
    int32 GetPackageCount() const { return PackageCount; }

    UFUNCTION(BlueprintPure, Category = "Inventory")
    bool IsFull() const { return PackageCount >= MAX_SLOTS; }

    /** True when no slots are occupied. */
    UFUNCTION(BlueprintPure, Category = "Inventory")
    bool IsEmpty() const { return PackageCount == 0; }

    UFUNCTION(BlueprintPure, Category = "Inventory")
    const TArray<bool>& GetSlotOccupied() const { return SlotOccupied; }

    UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
    FOnInventoryChanged OnInventoryChanged;

protected:
    virtual void BeginPlay() override;

private:
    TArray<bool> SlotOccupied;

    // Cached count for quick access (derived from SlotOccupied)
    UPROPERTY(VisibleAnywhere, Category = "Inventory|Debug")
    int32 PackageCount;

    /** Recomputes PackageCount and broadcasts OnInventoryChanged. */
    void NotifyInventoryChanged();
};