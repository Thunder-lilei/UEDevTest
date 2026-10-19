// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssetAuditEditorModeToolkit.h"
#include "AssetAuditEditorMode.h"
#include "Engine/Selection.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "EditorModeManager.h"

#define LOCTEXT_NAMESPACE "AssetAuditEditorModeToolkit"

FAssetAuditEditorModeToolkit::FAssetAuditEditorModeToolkit()
{
}

void FAssetAuditEditorModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost, TWeakObjectPtr<UEdMode> InOwningMode)
{
	FModeToolkit::Init(InitToolkitHost, InOwningMode);
}

void FAssetAuditEditorModeToolkit::GetToolPaletteNames(TArray<FName>& PaletteNames) const
{
	PaletteNames.Add(NAME_Default);
}


FName FAssetAuditEditorModeToolkit::GetToolkitFName() const
{
	return FName("AssetAuditEditorMode");
}

FText FAssetAuditEditorModeToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("DisplayName", "AssetAuditEditorMode Toolkit");
}

#undef LOCTEXT_NAMESPACE
