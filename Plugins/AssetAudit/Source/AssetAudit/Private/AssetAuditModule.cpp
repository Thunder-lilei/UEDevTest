// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssetAuditModule.h"
#include "AssetAuditEditorModeCommands.h"

#define LOCTEXT_NAMESPACE "AssetAuditModule"

void FAssetAuditModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FAssetAuditEditorModeCommands::Register();
}

void FAssetAuditModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FAssetAuditEditorModeCommands::Unregister();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAssetAuditModule, AssetAudit)