#pragma once

#include "CoreMinimal.h"
#include "../HeroCombatComponent.h"
#include "MageCombatComponent.generated.h"


UCLASS()
class SPRITELAND_API UMageCombatComponent : public UHeroCombatComponent
{
	GENERATED_BODY()

protected:
	virtual void Attack() override;
};
