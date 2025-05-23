#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeaponDataAsset.generated.h"


UCLASS()
class SPRITELAND_API UWeaponDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly)
	float MaxComboTime = 1.0f;

	UPROPERTY(EditDefaultsOnly)
	int32 MaxAttackCombo = 3;

	UPROPERTY(EditDefaultsOnly)
	float ComboTimer = 0.f;
};
