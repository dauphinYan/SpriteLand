#pragma once

#include "CoreMinimal.h"
#include "../WeaponBase.h"
#include "Wand.generated.h"

UCLASS()
class SPRITELAND_API AWand : public AWeaponBase
{
	GENERATED_BODY()
	
protected:
	virtual void NormalAttack() override;

protected:
	UPROPERTY(EditDefaultsOnly)
	class AFireBallProjectile* FireBall;


};
