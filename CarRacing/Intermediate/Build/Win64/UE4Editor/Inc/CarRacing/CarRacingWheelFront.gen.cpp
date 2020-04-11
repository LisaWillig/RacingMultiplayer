// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CarRacing/CarRacingWheelFront.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCarRacingWheelFront() {}
// Cross Module References
	CARRACING_API UClass* Z_Construct_UClass_UCarRacingWheelFront_NoRegister();
	CARRACING_API UClass* Z_Construct_UClass_UCarRacingWheelFront();
	PHYSXVEHICLES_API UClass* Z_Construct_UClass_UVehicleWheel();
	UPackage* Z_Construct_UPackage__Script_CarRacing();
// End Cross Module References
	void UCarRacingWheelFront::StaticRegisterNativesUCarRacingWheelFront()
	{
	}
	UClass* Z_Construct_UClass_UCarRacingWheelFront_NoRegister()
	{
		return UCarRacingWheelFront::StaticClass();
	}
	struct Z_Construct_UClass_UCarRacingWheelFront_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCarRacingWheelFront_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVehicleWheel,
		(UObject* (*)())Z_Construct_UPackage__Script_CarRacing,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarRacingWheelFront_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CarRacingWheelFront.h" },
		{ "ModuleRelativePath", "CarRacingWheelFront.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCarRacingWheelFront_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCarRacingWheelFront>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCarRacingWheelFront_Statics::ClassParams = {
		&UCarRacingWheelFront::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCarRacingWheelFront_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCarRacingWheelFront_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCarRacingWheelFront()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCarRacingWheelFront_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCarRacingWheelFront, 2123563802);
	template<> CARRACING_API UClass* StaticClass<UCarRacingWheelFront>()
	{
		return UCarRacingWheelFront::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCarRacingWheelFront(Z_Construct_UClass_UCarRacingWheelFront, &UCarRacingWheelFront::StaticClass, TEXT("/Script/CarRacing"), TEXT("UCarRacingWheelFront"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCarRacingWheelFront);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
