#include "HeatComponent.h"

UHeatComponent::UHeatComponent()
{
    CurrentHeat = 0;
}

//Adds heat amount to current heat
void UHeatComponent::AddHeat(int32 Amount)
{
    CurrentHeat += Amount;
    if (CurrentHeat > 100) {
        CurrentHeat = 100;
    }
}

//Decreases heat amount
void UHeatComponent::DecreaseHeat(int32 Amount)
{
    CurrentHeat -= Amount;
    if (CurrentHeat < 0) {
        CurrentHeat = 0;
    }
}

//Gets the heat
int32 UHeatComponent::GetHeat() const
{
    return CurrentHeat;
}

//Checks if heat is 100 (game should be ended if true)
bool UHeatComponent::IsMaxHeat() const
{
    return CurrentHeat >= 100;
}






