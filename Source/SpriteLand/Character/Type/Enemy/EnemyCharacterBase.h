#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpriteLand/Character/Common/CharacterInfo.h"
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

	UPROPERTY(EditDefaultsOnly)
	class UBoxComponent* CollisionBox;

protected: // Character attribute

	UPROPERTY(EditDefaultsOnly, Category = "Character Attribute")
	UDataTable* EnemyDatatable;

	UPROPERTY(EditDefaultsOnly, Category = "Character Attribute")
	EEnemyName EnemyName;

	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, Category = "Character Attribute")
	float MaxHealth = 100.f;

	UPROPERTY(EditDefaultsOnly, Category = "Character Attribute")
	float CurHealth = 100.f;

	UPROPERTY(EditDefaultsOnly, Category = "Character Attribute")
	float ManaValue = 100.f;

	UPROPERTY(EditDefaultsOnly, Category = "Character Attribute")
	float DefenseValue = 0.f;

	UPROPERTY(EditDefaultsOnly, Category = "Character Attribute")
	float AttackValue = 1.f;

	UPROPERTY(EditDefaultsOnly, Category = "Character Attribute")
	float AttackSpeed = 1.f;

	UPROPERTY(EditDefaultsOnly, Category = "Character Attribute")
	float MoveSpeed = 500.f;

	UPROPERTY(EditDefaultsOnly, Category = "Character Attribute")
	bool IsBoss = false;

protected:
	void PlayDeathMontage();

	UFUNCTION()
	void OnDeathMontageEnded();

private:
	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* DeathMontage;

	FTimerHandle DeathTimer;
};
