// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CarRacing/CarRacingWheelRear.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCarRacingWheelRear() {}
// Cross Module References
	CARRACING_API UClass* Z_Construct_UClass_UCarRacingWheelRear_NoRegister();
	CARRACING_API UClass* Z_Construct_UClass_UCarRacingWheelRear();
	PHYSXVEHICLES_API UClass* Z_Construct_UClass_UVehicleWheel();
	UPackage* Z_Construct_UPackage__Script_CarRacing();
// End Cross Module References
	void UCarRacingWheelRear::StaticRegisterNativesUCarRacingWheelRear()
	{
	}
	UClass* Z_Construct_UClass_UCarRacingWheelRear_NoRegister()
	{
		return UCarRacingWheelRear::StaticClass();
	}
	struct Z_Construct_UClass_UCarRacingWheelRear_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCarRacingWheelRear_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVehicleWheel,
		(UObject* (*)())Z_Construct_UPackage__Script_CarRacing,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCarRacingWheelRear_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CarRacingWheelRear.h" },
		{ "ModuleRelativePath", "CarRacingWheelRear.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCarRacingWheelRear_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCarRacingWheelRear>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCarRacingWheelRear_Statics::ClassParams = {
		&UCarRacingWheelRear::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UCarRacingWheelRear_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCarRacingWheelRear_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCarRacingWheelRear()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCarRacingWheelRear_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCarRacingWheelRear, 1299707565);
	template<> CARRACING_API UClass* StaticClass<UCarRacingWheelRear>()
	{
		return UCarRacingWheelRear::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCarRacingWheelRear(Z_Construct_UClass_UCarRacingWheelRear, &UCarRacingWheelRear::StaticClass, TEXT("/Script/CarRacing"), TEXT("UCarRacingWheelRear"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCarRacingWheelRear);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
