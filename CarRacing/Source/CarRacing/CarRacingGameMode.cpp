// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CarRacingGameMode.h"
#include "CarRacingPawn.h"
#include "CarRacingHud.h"

ACarRacingGameMode::ACarRacingGameMode()
{
	DefaultPawnClass = ACarRacingPawn::StaticClass();
	HUDClass = ACarRacingHud::StaticClass();
}
