// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssetAuditEditorMode.h"
#include "AssetAuditEditorModeToolkit.h"
#include "EdModeInteractiveToolsContext.h"
#include "InteractiveToolManager.h"
#include "AssetAuditEditorModeCommands.h"
#include "Modules/ModuleManager.h"


//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
// AddYourTool Step 1 - include the header file for your Tools here
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
#include "Tools/AssetAuditSimpleTool.h"
#include "Tools/AssetAuditInteractiveTool.h"

// step 2: register a ToolBuilder in FAssetAuditEditorMode::Enter() below


#define LOCTEXT_NAMESPACE "AssetAuditEditorMode"

const FEditorModeID UAssetAuditEditorMode::EM_AssetAuditEditorModeId = TEXT("EM_AssetAuditEditorMode");

FString UAssetAuditEditorMode::SimpleToolName = TEXT("AssetAudit_ActorInfoTool");
FString UAssetAuditEditorMode::InteractiveToolName = TEXT("AssetAudit_MeasureDistanceTool");


UAssetAuditEditorMode::UAssetAuditEditorMode()
{
	FModuleManager::Get().LoadModule("EditorStyle");

	// appearance and icon in the editing mode ribbon can be customized here
	Info = FEditorModeInfo(UAssetAuditEditorMode::EM_AssetAuditEditorModeId,
		LOCTEXT("ModeName", "AssetAudit"),
		FSlateIcon(),
		true);
}


UAssetAuditEditorMode::~UAssetAuditEditorMode()
{
}


void UAssetAuditEditorMode::ActorSelectionChangeNotify()
{
}

void UAssetAuditEditorMode::Enter()
{
	UEdMode::Enter();

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// AddYourTool Step 2 - register the ToolBuilders for your Tools here.
	// The string name you pass to the ToolManager is used to select/activate your ToolBuilder later.
	//////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////// 
	const FAssetAuditEditorModeCommands& SampleToolCommands = FAssetAuditEditorModeCommands::Get();

	RegisterTool(SampleToolCommands.SimpleTool, SimpleToolName, NewObject<UAssetAuditSimpleToolBuilder>(this));
	RegisterTool(SampleToolCommands.InteractiveTool, InteractiveToolName, NewObject<UAssetAuditInteractiveToolBuilder>(this));

	// active tool type is not relevant here, we just set to default
	GetToolManager()->SelectActiveToolType(EToolSide::Left, SimpleToolName);
}

void UAssetAuditEditorMode::CreateToolkit()
{
	Toolkit = MakeShareable(new FAssetAuditEditorModeToolkit);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> UAssetAuditEditorMode::GetModeCommands() const
{
	return FAssetAuditEditorModeCommands::Get().GetCommands();
}

#undef LOCTEXT_NAMESPACE
