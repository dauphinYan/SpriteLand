#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
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

	virtual void Dodge();

	virtual void JumpBegin();

	virtual void Attack();

	virtual void Equip(class AEquipmentBase* Equipment);
};
