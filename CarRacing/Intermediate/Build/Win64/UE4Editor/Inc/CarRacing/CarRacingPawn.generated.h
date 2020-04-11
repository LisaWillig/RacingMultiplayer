// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CARRACING_CarRacingPawn_generated_h
#error "CarRacingPawn.generated.h already included, missing '#pragma once' in CarRacingPawn.h"
#endif
#define CARRACING_CarRacingPawn_generated_h

#define CarRacing_Source_CarRacing_CarRacingPawn_h_17_SPARSE_DATA
#define CarRacing_Source_CarRacing_CarRacingPawn_h_17_RPC_WRAPPERS
#define CarRacing_Source_CarRacing_CarRacingPawn_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define CarRacing_Source_CarRacing_CarRacingPawn_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACarRacingPawn(); \
	friend struct Z_Construct_UClass_ACarRacingPawn_Statics; \
public: \
	DECLARE_CLASS(ACarRacingPawn, AWheeledVehicle, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CarRacing"), NO_API) \
	DECLARE_SERIALIZER(ACarRacingPawn)


#define CarRacing_Source_CarRacing_CarRacingPawn_h_17_INCLASS \
private: \
	static void StaticRegisterNativesACarRacingPawn(); \
	friend struct Z_Construct_UClass_ACarRacingPawn_Statics; \
public: \
	DECLARE_CLASS(ACarRacingPawn, AWheeledVehicle, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CarRacing"), NO_API) \
	DECLARE_SERIALIZER(ACarRacingPawn)


#define CarRacing_Source_CarRacing_CarRacingPawn_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACarRacingPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACarRacingPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACarRacingPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACarRacingPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACarRacingPawn(ACarRacingPawn&&); \
	NO_API ACarRacingPawn(const ACarRacingPawn&); \
public:


#define CarRacing_Source_CarRacing_CarRacingPawn_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACarRacingPawn(ACarRacingPawn&&); \
	NO_API ACarRacingPawn(const ACarRacingPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACarRacingPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACarRacingPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACarRacingPawn)


#define CarRacing_Source_CarRacing_CarRacingPawn_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SpringArm() { return STRUCT_OFFSET(ACarRacingPawn, SpringArm); } \
	FORCEINLINE static uint32 __PPO__Camera() { return STRUCT_OFFSET(ACarRacingPawn, Camera); } \
	FORCEINLINE static uint32 __PPO__InternalCameraBase() { return STRUCT_OFFSET(ACarRacingPawn, InternalCameraBase); } \
	FORCEINLINE static uint32 __PPO__InternalCamera() { return STRUCT_OFFSET(ACarRacingPawn, InternalCamera); } \
	FORCEINLINE static uint32 __PPO__InCarSpeed() { return STRUCT_OFFSET(ACarRacingPawn, InCarSpeed); } \
	FORCEINLINE static uint32 __PPO__InCarGear() { return STRUCT_OFFSET(ACarRacingPawn, InCarGear); }


#define CarRacing_Source_CarRacing_CarRacingPawn_h_14_PROLOG
#define CarRacing_Source_CarRacing_CarRacingPawn_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarRacing_Source_CarRacing_CarRacingPawn_h_17_PRIVATE_PROPERTY_OFFSET \
	CarRacing_Source_CarRacing_CarRacingPawn_h_17_SPARSE_DATA \
	CarRacing_Source_CarRacing_CarRacingPawn_h_17_RPC_WRAPPERS \
	CarRacing_Source_CarRacing_CarRacingPawn_h_17_INCLASS \
	CarRacing_Source_CarRacing_CarRacingPawn_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CarRacing_Source_CarRacing_CarRacingPawn_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarRacing_Source_CarRacing_CarRacingPawn_h_17_PRIVATE_PROPERTY_OFFSET \
	CarRacing_Source_CarRacing_CarRacingPawn_h_17_SPARSE_DATA \
	CarRacing_Source_CarRacing_CarRacingPawn_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	CarRacing_Source_CarRacing_CarRacingPawn_h_17_INCLASS_NO_PURE_DECLS \
	CarRacing_Source_CarRacing_CarRacingPawn_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CARRACING_API UClass* StaticClass<class ACarRacingPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CarRacing_Source_CarRacing_CarRacingPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
