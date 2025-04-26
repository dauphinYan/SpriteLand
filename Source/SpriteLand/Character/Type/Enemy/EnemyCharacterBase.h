#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacterBase.generated.h"


#define ECC_Enemy ECC_GameTraceChannel1

UCLASS()
class SPRITELAND_API AEnemyCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacterBase();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void ReceiveDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* InstigatorController, AActor* DamageCauser);

private:
	UPROPERTY(EditDefaultsOnly)
	class USoundWave* HurtSound;

	UPROPERTY(EditDefaultsOnly)
	class UNiagaraSystem* DamageFloatNiagara;
};
