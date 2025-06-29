// Copyright Epic Games, Inc. All Rights Reserved.

#include "GASUnrealProjectGameMode.h"
#include "GASUnrealProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGASUnrealProjectGameMode::AGASUnrealProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
