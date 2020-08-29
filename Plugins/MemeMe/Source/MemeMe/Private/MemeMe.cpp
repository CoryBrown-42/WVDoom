// Copyright Epic Games, Inc. All Rights Reserved.

#include "MemeMe.h"
#include "MemeMeStyle.h"
#include "MemeMeCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName MemeMeTabName("Meme Me");

#define LOCTEXT_NAMESPACE "FMemeMeModule"

void FMemeMeModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FMemeMeStyle::Initialize();
	FMemeMeStyle::ReloadTextures();

	FMemeMeCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FMemeMeCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FMemeMeModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMemeMeModule::RegisterMenus));
}

void FMemeMeModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FMemeMeStyle::Shutdown();

	FMemeMeCommands::Unregister();
}

void FMemeMeModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
		LOCTEXT("PluginButtonDialogText", "Thank you for your time."),
		FText::FromString(TEXT("FMemeMeModule::PluginButtonClicked()")),
		FText::FromString(TEXT("MemeMe.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FMemeMeModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FMemeMeCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMemeMeCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMemeMeModule, MemeMe)