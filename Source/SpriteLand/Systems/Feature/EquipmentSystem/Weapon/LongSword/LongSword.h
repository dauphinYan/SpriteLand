#pragma once

#include "CoreMinimal.h"
#include "../WeaponBase.h"
#include "LongSword.generated.h"

UCLASS()
class SPRITELAND_API ALongSword : public AWeaponBase
{
	GENERATED_BODY()
	
public:
	ALongSword();

protected:
	virtual void BeginPlay() override;

public:
	virtual void AttackStart() override;

	virtual void AttackEnd() override;

protected:
	UPROPERTY(EditDefaultsOnly)
	class UBoxComponent* CollisionBox;

	UPROPERTY(EditDefaultsOnly)
	class USoundCue* HitSound;

	UFUNCTION()
	virtual void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	TArray<AActor*> HitTargets;

	float MinHitInterval = 0.3f;

	TMap<AActor*, float> LastHitTimeMap;
};
