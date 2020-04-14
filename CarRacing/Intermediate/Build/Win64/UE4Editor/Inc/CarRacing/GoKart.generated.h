// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CARRACING_GoKart_generated_h
#error "GoKart.generated.h already included, missing '#pragma once' in GoKart.h"
#endif
#define CARRACING_GoKart_generated_h

#define CarRacing_Source_CarRacing_GoKart_h_12_SPARSE_DATA
#define CarRacing_Source_CarRacing_GoKart_h_12_RPC_WRAPPERS
#define CarRacing_Source_CarRacing_GoKart_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define CarRacing_Source_CarRacing_GoKart_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGoKart(); \
	friend struct Z_Construct_UClass_AGoKart_Statics; \
public: \
	DECLARE_CLASS(AGoKart, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CarRacing"), NO_API) \
	DECLARE_SERIALIZER(AGoKart)


#define CarRacing_Source_CarRacing_GoKart_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAGoKart(); \
	friend struct Z_Construct_UClass_AGoKart_Statics; \
public: \
	DECLARE_CLASS(AGoKart, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CarRacing"), NO_API) \
	DECLARE_SERIALIZER(AGoKart)


#define CarRacing_Source_CarRacing_GoKart_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGoKart(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGoKart) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGoKart); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGoKart); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGoKart(AGoKart&&); \
	NO_API AGoKart(const AGoKart&); \
public:


#define CarRacing_Source_CarRacing_GoKart_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGoKart(AGoKart&&); \
	NO_API AGoKart(const AGoKart&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGoKart); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGoKart); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGoKart)


#define CarRacing_Source_CarRacing_GoKart_h_12_PRIVATE_PROPERTY_OFFSET
#define CarRacing_Source_CarRacing_GoKart_h_9_PROLOG
#define CarRacing_Source_CarRacing_GoKart_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarRacing_Source_CarRacing_GoKart_h_12_PRIVATE_PROPERTY_OFFSET \
	CarRacing_Source_CarRacing_GoKart_h_12_SPARSE_DATA \
	CarRacing_Source_CarRacing_GoKart_h_12_RPC_WRAPPERS \
	CarRacing_Source_CarRacing_GoKart_h_12_INCLASS \
	CarRacing_Source_CarRacing_GoKart_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CarRacing_Source_CarRacing_GoKart_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CarRacing_Source_CarRacing_GoKart_h_12_PRIVATE_PROPERTY_OFFSET \
	CarRacing_Source_CarRacing_GoKart_h_12_SPARSE_DATA \
	CarRacing_Source_CarRacing_GoKart_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	CarRacing_Source_CarRacing_GoKart_h_12_INCLASS_NO_PURE_DECLS \
	CarRacing_Source_CarRacing_GoKart_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CARRACING_API UClass* StaticClass<class AGoKart>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CarRacing_Source_CarRacing_GoKart_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
