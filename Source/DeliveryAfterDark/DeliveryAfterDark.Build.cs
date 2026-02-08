// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DeliveryAfterDark : ModuleRules
{
	public DeliveryAfterDark(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"DeliveryAfterDark",
			"DeliveryAfterDark/Variant_Platforming",
			"DeliveryAfterDark/Variant_Platforming/Animation",
			"DeliveryAfterDark/Variant_Combat",
			"DeliveryAfterDark/Variant_Combat/AI",
			"DeliveryAfterDark/Variant_Combat/Animation",
			"DeliveryAfterDark/Variant_Combat/Gameplay",
			"DeliveryAfterDark/Variant_Combat/Interfaces",
			"DeliveryAfterDark/Variant_Combat/UI",
			"DeliveryAfterDark/Variant_SideScrolling",
			"DeliveryAfterDark/Variant_SideScrolling/AI",
			"DeliveryAfterDark/Variant_SideScrolling/Gameplay",
			"DeliveryAfterDark/Variant_SideScrolling/Interfaces",
			"DeliveryAfterDark/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
