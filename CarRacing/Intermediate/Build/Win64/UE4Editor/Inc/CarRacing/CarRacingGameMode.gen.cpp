// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CarRacing/CarRacingGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCarRacingGameMode() {}
// Cross Module References
	CARRACING_API UClass* Z_Construct_UClass_ACarRacingGameMode_NoRegister();
	CARRACING_API UClass* Z_Construct_UClass_ACarRacingGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_CarRacing();
// End Cross Module References
	void ACarRacingGameMode::StaticRegisterNativesACarRacingGameMode()
	{
	}
	UClass* Z_Construct_UClass_ACarRacingGameMode_NoRegister()
	{
		return ACarRacingGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ACarRacingGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACarRacingGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_CarRacing,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACarRacingGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "CarRacingGameMode.h" },
		{ "ModuleRelativePath", "CarRacingGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACarRacingGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACarRacingGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACarRacingGameMode_Statics::ClassParams = {
		&ACarRacingGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ACarRacingGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACarRacingGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACarRacingGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACarRacingGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACarRacingGameMode, 1996073973);
	template<> CARRACING_API UClass* StaticClass<ACarRacingGameMode>()
	{
		return ACarRacingGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACarRacingGameMode(Z_Construct_UClass_ACarRacingGameMode, &ACarRacingGameMode::StaticClass, TEXT("/Script/CarRacing"), TEXT("ACarRacingGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACarRacingGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
