// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class x7 : ModuleRules
{
	public x7(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		string GauchePath = ModuleDirectory + "/../Gauche/";
		string LibPrefix = GauchePath + "src/";
		// string LibPostfixAndExt = ".a";

		// PublicAdditionalLibraries.Add(LibPrefix + "libgauche-static-0.9" + LibPostfixAndExt);
		PublicLibraryPaths.Add(LibPrefix);
		PublicAdditionalLibraries.Add("gauche-static-0.9");
		PublicAdditionalLibraries.Add("util");

		PublicIncludePaths.Add(LibPrefix);
		PublicIncludePaths.Add(GauchePath + "gc/include");

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }
	}
}
