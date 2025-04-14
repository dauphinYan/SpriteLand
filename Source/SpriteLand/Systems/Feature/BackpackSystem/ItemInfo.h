#pragma once

#include "CoreMinimal.h"
#include "ItemInfo.generated.h"

UENUM(BlueprintType)
enum class EItemName : uint8
{
	Unknown,
	LongSword_Wood,
	LongSword_Iron,
	LongSword_Diamond,
	HealthPotion_Small,
	ManaPotion_Small,
	Apple,
	Banana,
	Pear
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Unknown,
	Consumable,
	Equipment,
	QuestItem,
	Miscellaneous
};

UENUM(BlueprintType)
enum class EUsableEffectType : uint8
{
	Unknown,
	RestoreHP,
	RestoreMP,
	AddExperience
};

USTRUCT(BlueprintType)
struct FItemInfoBase :public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxStackSize;
};

USTRUCT(BlueprintType)
struct FUsableItemInfo : public FItemInfoBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EUsableEffectType EffectType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float EffectValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bAffectSelf = true;
};

USTRUCT(BlueprintType)
struct FEquipmentItemInfo : public FItemInfoBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttackValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DefensiveValue;

};