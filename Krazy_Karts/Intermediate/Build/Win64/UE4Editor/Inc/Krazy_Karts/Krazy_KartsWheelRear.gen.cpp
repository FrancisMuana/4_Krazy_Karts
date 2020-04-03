// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Krazy_Karts/Krazy_KartsWheelRear.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKrazy_KartsWheelRear() {}
// Cross Module References
	KRAZY_KARTS_API UClass* Z_Construct_UClass_UKrazy_KartsWheelRear_NoRegister();
	KRAZY_KARTS_API UClass* Z_Construct_UClass_UKrazy_KartsWheelRear();
	PHYSXVEHICLES_API UClass* Z_Construct_UClass_UVehicleWheel();
	UPackage* Z_Construct_UPackage__Script_Krazy_Karts();
// End Cross Module References
	void UKrazy_KartsWheelRear::StaticRegisterNativesUKrazy_KartsWheelRear()
	{
	}
	UClass* Z_Construct_UClass_UKrazy_KartsWheelRear_NoRegister()
	{
		return UKrazy_KartsWheelRear::StaticClass();
	}
	struct Z_Construct_UClass_UKrazy_KartsWheelRear_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UKrazy_KartsWheelRear_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVehicleWheel,
		(UObject* (*)())Z_Construct_UPackage__Script_Krazy_Karts,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKrazy_KartsWheelRear_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Krazy_KartsWheelRear.h" },
		{ "ModuleRelativePath", "Krazy_KartsWheelRear.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UKrazy_KartsWheelRear_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UKrazy_KartsWheelRear>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UKrazy_KartsWheelRear_Statics::ClassParams = {
		&UKrazy_KartsWheelRear::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UKrazy_KartsWheelRear_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UKrazy_KartsWheelRear_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UKrazy_KartsWheelRear()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UKrazy_KartsWheelRear_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UKrazy_KartsWheelRear, 314283645);
	template<> KRAZY_KARTS_API UClass* StaticClass<UKrazy_KartsWheelRear>()
	{
		return UKrazy_KartsWheelRear::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UKrazy_KartsWheelRear(Z_Construct_UClass_UKrazy_KartsWheelRear, &UKrazy_KartsWheelRear::StaticClass, TEXT("/Script/Krazy_Karts"), TEXT("UKrazy_KartsWheelRear"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UKrazy_KartsWheelRear);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
