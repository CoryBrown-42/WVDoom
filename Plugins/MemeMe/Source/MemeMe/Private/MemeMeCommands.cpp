// Copyright Epic Games, Inc. All Rights Reserved.

#include "MemeMeCommands.h"
#include "Engine.h"

#define LOCTEXT_NAMESPACE "FMemeMeModule"

void FMemeMeCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "MemeMe", "Execute MemeMe action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
