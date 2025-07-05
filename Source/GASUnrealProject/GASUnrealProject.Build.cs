// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GASUnrealProject : ModuleRules
{
	public GASUnrealProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", 
			"GameplayAbilities", "GameplayTasks", "GameplayTags" });
	}
}
