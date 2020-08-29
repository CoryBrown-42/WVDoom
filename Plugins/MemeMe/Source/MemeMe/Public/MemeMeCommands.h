// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MemeMeStyle.h"

class FMemeMeCommands : public TCommands<FMemeMeCommands>
{
public:

	FMemeMeCommands()
		: TCommands<FMemeMeCommands>(TEXT("MemeMe"), NSLOCTEXT("Contexts", "MemeMe", "MemeMe Plugin"), NAME_None, FMemeMeStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
