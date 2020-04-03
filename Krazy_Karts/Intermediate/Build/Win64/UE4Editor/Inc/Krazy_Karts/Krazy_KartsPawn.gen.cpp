// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Krazy_Karts/Krazy_KartsPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKrazy_KartsPawn() {}
// Cross Module References
	KRAZY_KARTS_API UClass* Z_Construct_UClass_AKrazy_KartsPawn_NoRegister();
	KRAZY_KARTS_API UClass* Z_Construct_UClass_AKrazy_KartsPawn();
	PHYSXVEHICLES_API UClass* Z_Construct_UClass_AWheeledVehicle();
	UPackage* Z_Construct_UPackage__Script_Krazy_Karts();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	ENGINE_API UClass* Z_Construct_UClass_UTextRenderComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	void AKrazy_KartsPawn::StaticRegisterNativesAKrazy_KartsPawn()
	{
	}
	UClass* Z_Construct_UClass_AKrazy_KartsPawn_NoRegister()
	{
		return AKrazy_KartsPawn::StaticClass();
	}
	struct Z_Construct_UClass_AKrazy_KartsPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bInReverseGear_MetaData[];
#endif
		static void NewProp_bInReverseGear_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInReverseGear;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bInCarCameraActive_MetaData[];
#endif
		static void NewProp_bInCarCameraActive_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInCarCameraActive;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GearDisplayReverseColor_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GearDisplayReverseColor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GearDisplayColor_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GearDisplayColor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GearDisplayString_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_GearDisplayString;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpeedDisplayString_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_SpeedDisplayString;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InCarGear_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InCarGear;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InCarSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InCarSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InternalCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InternalCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InternalCameraBase_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InternalCameraBase;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Camera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AKrazy_KartsPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AWheeledVehicle,
		(UObject* (*)())Z_Construct_UPackage__Script_Krazy_Karts,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Krazy_KartsPawn.h" },
		{ "ModuleRelativePath", "Krazy_KartsPawn.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInReverseGear_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Are we in reverse gear */" },
		{ "ModuleRelativePath", "Krazy_KartsPawn.h" },
		{ "ToolTip", "Are we in reverse gear" },
	};
#endif
	void Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInReverseGear_SetBit(void* Obj)
	{
		((AKrazy_KartsPawn*)Obj)->bInReverseGear = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInReverseGear = { "bInReverseGear", nullptr, (EPropertyFlags)0x0010000000030015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AKrazy_KartsPawn), &Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInReverseGear_SetBit, METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInReverseGear_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInReverseGear_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInCarCameraActive_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Are we using incar camera */" },
		{ "ModuleRelativePath", "Krazy_KartsPawn.h" },
		{ "ToolTip", "Are we using incar camera" },
	};
#endif
	void Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInCarCameraActive_SetBit(void* Obj)
	{
		((AKrazy_KartsPawn*)Obj)->bInCarCameraActive = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInCarCameraActive = { "bInCarCameraActive", nullptr, (EPropertyFlags)0x0010000000030015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AKrazy_KartsPawn), &Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInCarCameraActive_SetBit, METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInCarCameraActive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInCarCameraActive_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayReverseColor_MetaData[] = {
		{ "Category", "Display" },
		{ "Comment", "/** The color of the incar gear text when in reverse */" },
		{ "ModuleRelativePath", "Krazy_KartsPawn.h" },
		{ "ToolTip", "The color of the incar gear text when in reverse" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayReverseColor = { "GearDisplayReverseColor", nullptr, (EPropertyFlags)0x0010000000030015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AKrazy_KartsPawn, GearDisplayReverseColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayReverseColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayReverseColor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayColor_MetaData[] = {
		{ "Category", "Display" },
		{ "Comment", "/** The color of the incar gear text in forward gears */" },
		{ "ModuleRelativePath", "Krazy_KartsPawn.h" },
		{ "ToolTip", "The color of the incar gear text in forward gears" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayColor = { "GearDisplayColor", nullptr, (EPropertyFlags)0x0010000000030015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AKrazy_KartsPawn, GearDisplayColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayColor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayString_MetaData[] = {
		{ "Category", "Display" },
		{ "Comment", "/** The current gear as a string (R,N, 1,2 etc) */" },
		{ "ModuleRelativePath", "Krazy_KartsPawn.h" },
		{ "ToolTip", "The current gear as a string (R,N, 1,2 etc)" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayString = { "GearDisplayString", nullptr, (EPropertyFlags)0x0010000000030015, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AKrazy_KartsPawn, GearDisplayString), METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayString_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_SpeedDisplayString_MetaData[] = {
		{ "Category", "Display" },
		{ "Comment", "/** The current speed as a string eg 10 km/h */" },
		{ "ModuleRelativePath", "Krazy_KartsPawn.h" },
		{ "ToolTip", "The current speed as a string eg 10 km/h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_SpeedDisplayString = { "SpeedDisplayString", nullptr, (EPropertyFlags)0x0010000000030015, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AKrazy_KartsPawn, SpeedDisplayString), METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_SpeedDisplayString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_SpeedDisplayString_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InCarGear_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "Comment", "/** Text component for the In-Car gear */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Krazy_KartsPawn.h" },
		{ "ToolTip", "Text component for the In-Car gear" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InCarGear = { "InCarGear", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AKrazy_KartsPawn, InCarGear), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InCarGear_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InCarGear_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InCarSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "Comment", "/** Text component for the In-Car speed */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Krazy_KartsPawn.h" },
		{ "ToolTip", "Text component for the In-Car speed" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InCarSpeed = { "InCarSpeed", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AKrazy_KartsPawn, InCarSpeed), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InCarSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InCarSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InternalCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera component for the In-Car view */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Krazy_KartsPawn.h" },
		{ "ToolTip", "Camera component for the In-Car view" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InternalCamera = { "InternalCamera", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AKrazy_KartsPawn, InternalCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InternalCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InternalCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InternalCameraBase_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** SCene component for the In-Car view origin */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Krazy_KartsPawn.h" },
		{ "ToolTip", "SCene component for the In-Car view origin" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InternalCameraBase = { "InternalCameraBase", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AKrazy_KartsPawn, InternalCameraBase), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InternalCameraBase_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InternalCameraBase_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_Camera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera component that will be our viewpoint */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Krazy_KartsPawn.h" },
		{ "ToolTip", "Camera component that will be our viewpoint" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AKrazy_KartsPawn, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_Camera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_Camera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_SpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Spring arm that will offset the camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Krazy_KartsPawn.h" },
		{ "ToolTip", "Spring arm that will offset the camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AKrazy_KartsPawn, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_SpringArm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_SpringArm_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AKrazy_KartsPawn_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInReverseGear,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_bInCarCameraActive,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayReverseColor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayColor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_GearDisplayString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_SpeedDisplayString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InCarGear,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InCarSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InternalCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_InternalCameraBase,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_Camera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKrazy_KartsPawn_Statics::NewProp_SpringArm,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AKrazy_KartsPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AKrazy_KartsPawn>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AKrazy_KartsPawn_Statics::ClassParams = {
		&AKrazy_KartsPawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AKrazy_KartsPawn_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AKrazy_KartsPawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AKrazy_KartsPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AKrazy_KartsPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AKrazy_KartsPawn_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AKrazy_KartsPawn, 2840455666);
	template<> KRAZY_KARTS_API UClass* StaticClass<AKrazy_KartsPawn>()
	{
		return AKrazy_KartsPawn::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AKrazy_KartsPawn(Z_Construct_UClass_AKrazy_KartsPawn, &AKrazy_KartsPawn::StaticClass, TEXT("/Script/Krazy_Karts"), TEXT("AKrazy_KartsPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AKrazy_KartsPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
