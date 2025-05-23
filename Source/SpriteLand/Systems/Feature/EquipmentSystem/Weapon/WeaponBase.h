#pragma once

#include "CoreMinimal.h"
#include "SpriteLand/Systems/Feature/EquipmentSystem/EquipmentBase.h"
#include "WeaponDataAsset.h"
#include "WeaponBase.generated.h"

#define ECC_Enemy ECC_GameTraceChannel1

UCLASS()
class SPRITELAND_API AWeaponBase : public AEquipmentBase
{
	GENERATED_BODY()

public:
	AWeaponBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void AttackStart();

	virtual void AttackEnd();

	virtual void NormalAttack();

public:
	UPROPERTY(EditDefaultsOnly)
	const UWeaponDataAsset* WeaponDataAsset;

};
