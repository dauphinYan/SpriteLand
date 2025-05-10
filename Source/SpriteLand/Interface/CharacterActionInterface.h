#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/ItemInfo.h"
#include "CharacterActionInterface.generated.h"

UINTERFACE(MinimalAPI)
class UCharacterActionInterface : public UInterface
{
	GENERATED_BODY()
};


class SPRITELAND_API ICharacterActionInterface
{
	GENERATED_BODY()

public:
	virtual void Move(const struct FInputActionValue& Value);

	virtual void Look(const FInputActionValue& Value);

	virtual void StartRunning();

	virtual void StopRunning();

	virtual void Dodge();

	virtual void JumpBegin();

	virtual void Attack();

	virtual void Equip(class AEquipmentBase* Equipment);

	virtual void UnEquip(EEquipmentType EquipmentType);
};
