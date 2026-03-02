#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
    //starts full
    SlotOccupied.Init(true, 4);
}

bool UInventoryComponent::DeliverPackage()
{
    //find the last true and make it false
    for (int32 i = SlotOccupied.Num() - 1; i >= 0; i--)
    {
        if (SlotOccupied[i])
        {
            SlotOccupied[i] = false;
            return true;
        }
    }
    return false;
}

int32 UInventoryComponent::GetPackageCount() const
{
    int32 Count = 0;
    for (bool bBusy : SlotOccupied) if (bBusy) Count++;
    return Count;
}