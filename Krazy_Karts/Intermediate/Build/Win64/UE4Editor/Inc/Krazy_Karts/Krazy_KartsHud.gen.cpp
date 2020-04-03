// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Krazy_Karts/Krazy_KartsHud.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKrazy_KartsHud() {}
// Cross Module References
	KRAZY_KARTS_API UClass* Z_Construct_UClass_AKrazy_KartsHud_NoRegister();
	KRAZY_KARTS_API UClass* Z_Construct_UClass_AKrazy_KartsHud();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_Krazy_Karts();
	ENGINE_API UClass* Z_Construct_UClass_UFont_NoRegister();
// End Cross Module References
	void AKrazy_KartsHud::StaticRegisterNativesAKrazy_KartsHud()
	{
	}
	UClass* Z_Construct_UClass_AKrazy_KartsHud_NoRegister()
	{
		return AKrazy_KartsHud::StaticClass();
	}
	struct Z_Construct_UClass_AKrazy_KartsHud_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HUDFont_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HUDFont;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AKrazy_KartsHud_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_Krazy_Karts,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsHud_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "Krazy_KartsHud.h" },
		{ "ModuleRelativePath", "Krazy_KartsHud.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsHud_Statics::NewProp_HUDFont_MetaData[] = {
		{ "Comment", "/** Font used to render the vehicle info */" },
		{ "ModuleRelativePath", "Krazy_KartsHud.h" },
		{ "ToolTip", "Font used to render the vehicle info" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AKrazy_KartsHud_Statics::NewProp_HUDFont = { "HUDFont", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AKrazy_KartsHud, HUDFont), Z_Construct_UClass_UFont_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsHud_Statics::NewProp_HUDFont_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsHud_Statics::NewProp_HUDFont_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AKrazy_KartsHud_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKrazy_KartsHud_Statics::NewProp_HUDFont,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AKrazy_KartsHud_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AKrazy_KartsHud>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AKrazy_KartsHud_Statics::ClassParams = {
		&AKrazy_KartsHud::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AKrazy_KartsHud_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsHud_Statics::PropPointers),
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsHud_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsHud_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AKrazy_KartsHud()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AKrazy_KartsHud_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AKrazy_KartsHud, 4072818707);
	template<> KRAZY_KARTS_API UClass* StaticClass<AKrazy_KartsHud>()
	{
		return AKrazy_KartsHud::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AKrazy_KartsHud(Z_Construct_UClass_AKrazy_KartsHud, &AKrazy_KartsHud::StaticClass, TEXT("/Script/Krazy_Karts"), TEXT("AKrazy_KartsHud"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AKrazy_KartsHud);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
