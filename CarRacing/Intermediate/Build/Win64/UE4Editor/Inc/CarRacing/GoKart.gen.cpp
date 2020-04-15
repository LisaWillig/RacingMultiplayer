// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CarRacing/GoKart.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGoKart() {}
// Cross Module References
	CARRACING_API UClass* Z_Construct_UClass_AGoKart_NoRegister();
	CARRACING_API UClass* Z_Construct_UClass_AGoKart();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_CarRacing();
// End Cross Module References
	void AGoKart::StaticRegisterNativesAGoKart()
	{
	}
	UClass* Z_Construct_UClass_AGoKart_NoRegister()
	{
		return AGoKart::StaticClass();
	}
	struct Z_Construct_UClass_AGoKart_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxDegreePerSecond_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxDegreePerSecond;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RRCoefficient_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RRCoefficient;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DragCoefficient_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DragCoefficient;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxDrivingForce_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxDrivingForce;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Mass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGoKart_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_CarRacing,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGoKart_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "GoKart.h" },
		{ "ModuleRelativePath", "GoKart.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGoKart_Statics::NewProp_MaxDegreePerSecond_MetaData[] = {
		{ "Category", "GoKart" },
		{ "Comment", "// Air Resistance Coefficient\n" },
		{ "ModuleRelativePath", "GoKart.h" },
		{ "ToolTip", "Air Resistance Coefficient" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGoKart_Statics::NewProp_MaxDegreePerSecond = { "MaxDegreePerSecond", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGoKart, MaxDegreePerSecond), METADATA_PARAMS(Z_Construct_UClass_AGoKart_Statics::NewProp_MaxDegreePerSecond_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGoKart_Statics::NewProp_MaxDegreePerSecond_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGoKart_Statics::NewProp_RRCoefficient_MetaData[] = {
		{ "Category", "GoKart" },
		{ "Comment", "// Air Resistance Coefficient\n" },
		{ "ModuleRelativePath", "GoKart.h" },
		{ "ToolTip", "Air Resistance Coefficient" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGoKart_Statics::NewProp_RRCoefficient = { "RRCoefficient", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGoKart, RRCoefficient), METADATA_PARAMS(Z_Construct_UClass_AGoKart_Statics::NewProp_RRCoefficient_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGoKart_Statics::NewProp_RRCoefficient_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGoKart_Statics::NewProp_DragCoefficient_MetaData[] = {
		{ "Category", "GoKart" },
		{ "Comment", "//N\n" },
		{ "ModuleRelativePath", "GoKart.h" },
		{ "ToolTip", "N" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGoKart_Statics::NewProp_DragCoefficient = { "DragCoefficient", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGoKart, DragCoefficient), METADATA_PARAMS(Z_Construct_UClass_AGoKart_Statics::NewProp_DragCoefficient_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGoKart_Statics::NewProp_DragCoefficient_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGoKart_Statics::NewProp_MaxDrivingForce_MetaData[] = {
		{ "Category", "GoKart" },
		{ "Comment", "//kg\n" },
		{ "ModuleRelativePath", "GoKart.h" },
		{ "ToolTip", "kg" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGoKart_Statics::NewProp_MaxDrivingForce = { "MaxDrivingForce", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGoKart, MaxDrivingForce), METADATA_PARAMS(Z_Construct_UClass_AGoKart_Statics::NewProp_MaxDrivingForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGoKart_Statics::NewProp_MaxDrivingForce_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGoKart_Statics::NewProp_Mass_MetaData[] = {
		{ "Category", "GoKart" },
		{ "ModuleRelativePath", "GoKart.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGoKart_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGoKart, Mass), METADATA_PARAMS(Z_Construct_UClass_AGoKart_Statics::NewProp_Mass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGoKart_Statics::NewProp_Mass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGoKart_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGoKart_Statics::NewProp_MaxDegreePerSecond,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGoKart_Statics::NewProp_RRCoefficient,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGoKart_Statics::NewProp_DragCoefficient,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGoKart_Statics::NewProp_MaxDrivingForce,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGoKart_Statics::NewProp_Mass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGoKart_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGoKart>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGoKart_Statics::ClassParams = {
		&AGoKart::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGoKart_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGoKart_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGoKart_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGoKart_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGoKart()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGoKart_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGoKart, 94099633);
	template<> CARRACING_API UClass* StaticClass<AGoKart>()
	{
		return AGoKart::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGoKart(Z_Construct_UClass_AGoKart, &AGoKart::StaticClass, TEXT("/Script/CarRacing"), TEXT("AGoKart"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGoKart);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
