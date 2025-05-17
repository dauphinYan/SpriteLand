#pragma once

#include "CoreMinimal.h"
#include "SpriteLand/Systems/Feature/EquipmentSystem/EquipmentBase.h"
#include "WeaponBase.generated.h"

#define ECC_Enemy ECC_GameTraceChannel1

UCLASS()
class SPRITELAND_API AWeaponBase : public AEquipmentBase
{
	GENERATED_BODY()

public:
	AWeaponBase();
	virtual void AttackStart();
	virtual void AttackEnd();

protected:
	virtual void BeginPlay() override;

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
