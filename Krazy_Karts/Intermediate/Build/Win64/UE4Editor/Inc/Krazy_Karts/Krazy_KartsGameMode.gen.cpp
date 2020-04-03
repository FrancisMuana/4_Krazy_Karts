// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Krazy_Karts/Krazy_KartsGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKrazy_KartsGameMode() {}
// Cross Module References
	KRAZY_KARTS_API UClass* Z_Construct_UClass_AKrazy_KartsGameMode_NoRegister();
	KRAZY_KARTS_API UClass* Z_Construct_UClass_AKrazy_KartsGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Krazy_Karts();
// End Cross Module References
	void AKrazy_KartsGameMode::StaticRegisterNativesAKrazy_KartsGameMode()
	{
	}
	UClass* Z_Construct_UClass_AKrazy_KartsGameMode_NoRegister()
	{
		return AKrazy_KartsGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AKrazy_KartsGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AKrazy_KartsGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Krazy_Karts,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Krazy_KartsGameMode.h" },
		{ "ModuleRelativePath", "Krazy_KartsGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AKrazy_KartsGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AKrazy_KartsGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AKrazy_KartsGameMode_Statics::ClassParams = {
		&AKrazy_KartsGameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AKrazy_KartsGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AKrazy_KartsGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AKrazy_KartsGameMode, 1912669624);
	template<> KRAZY_KARTS_API UClass* StaticClass<AKrazy_KartsGameMode>()
	{
		return AKrazy_KartsGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AKrazy_KartsGameMode(Z_Construct_UClass_AKrazy_KartsGameMode, &AKrazy_KartsGameMode::StaticClass, TEXT("/Script/Krazy_Karts"), TEXT("AKrazy_KartsGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AKrazy_KartsGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
