// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/HUD.h"
#include "CarRacingHud.generated.h"


UCLASS(config = Game)
class ACarRacingHud : public AHUD
{
	GENERATED_BODY()

public:
	ACarRacingHud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface
};
