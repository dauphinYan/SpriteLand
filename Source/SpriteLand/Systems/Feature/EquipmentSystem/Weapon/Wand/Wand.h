#pragma once

#include "CoreMinimal.h"
#include "../WeaponBase.h"
#include "Wand.generated.h"

class AFireBallProjectile;

UCLASS()
class SPRITELAND_API AWand : public AWeaponBase
{
	GENERATED_BODY()
	
protected:
	virtual void AttackStart() override;

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AFireBallProjectile> FireBallClass;


};
