#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CharacterActonInterface.generated.h"

UINTERFACE(MinimalAPI)
class UCharacterActonInterface : public UInterface
{
	GENERATED_BODY()
};


class SPRITELAND_API ICharacterActonInterface
{
	GENERATED_BODY()

public:

	virtual void Move(const struct FInputActionValue& Value) = 0;

	virtual void Look(const FInputActionValue& Value) = 0;

	virtual void Jump() = 0;

	virtual void Dodget() = 0;
};
