// Copyright Epic Games, Inc. All Rights Reserved.

#include "EquipmentPluginGameMode.h"
#include "EquipmentPluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEquipmentPluginGameMode::AEquipmentPluginGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
