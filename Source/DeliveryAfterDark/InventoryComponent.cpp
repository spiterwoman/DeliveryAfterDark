#include "InventoryComponent.h"
#include "Engine/Engine.h" // for optional GEngine debug messages

UInventoryComponent::UInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;

    // Initialize all 4 slots as empty
    SlotOccupied.Init(false, MAX_SLOTS);
    PackageCount = 0;
}

void UInventoryComponent::BeginPlay()
{
    Super::BeginPlay();
    // Nothing to do on begin play — slots are already initialized in constructor
}

bool UInventoryComponent::PickupPackage()
{
    if (IsFull())
    {
        return false;
    }

    // Find the first empty slot and fill it
    for (int32 i = 0; i < MAX_SLOTS; i++)
    {
        if (!SlotOccupied[i])
        {
            SlotOccupied[i] = true;
            NotifyInventoryChanged();

            return true;
        }
    }

    // Should never reach here given the IsFull() check above
    return false;
}

bool UInventoryComponent::DeliverPackage()
{
    if (IsEmpty())
    {
        return false;
    }

    // Remove from the last occupied slot 
    for (int32 i = MAX_SLOTS - 1; i >= 0; i--)
    {
        if (SlotOccupied[i])
        {
            SlotOccupied[i] = false;
            NotifyInventoryChanged();

            return true;
        }
    }

    // Should never reach here given the IsEmpty() check above
    return false;
}

void UInventoryComponent::NotifyInventoryChanged()
{
    // Recount from source of truth (SlotOccupied array)
    PackageCount = 0;
    for (bool bOccupied : SlotOccupied)
    {
        if (bOccupied) PackageCount++;
    }

    // Broadcast to any listeners (UI widgets, game mode, etc.)
    OnInventoryChanged.Broadcast(SlotOccupied, PackageCount);
}