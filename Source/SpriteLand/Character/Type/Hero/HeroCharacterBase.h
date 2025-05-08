#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpriteLand/Interface/CharacterActionInterface.h"
#include "HeroCharacterBase.generated.h"

UCLASS()
class SPRITELAND_API AHeroCharacterBase : public ACharacter, public ICharacterActionInterface
{
	GENERATED_BODY()

public:
	AHeroCharacterBase();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UEquipmentComponent* EquipmentComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UHeroCombatComponent* CombatComponent;

	UPROPERTY()
	class ASpriteLandPlayerController* PlayerController;

	UPROPERTY(EditDefaultsOnly)
	class UAnimMontage* DodgeMontage;

protected:
	virtual void Move(const struct FInputActionValue& Value) override;

	virtual void Look(const FInputActionValue& Value) override;

	virtual void Dodge() override;

	virtual void JumpBegin() override;

	virtual void Attack() override;

	UFUNCTION(BlueprintCallable)
	virtual void Equip(AEquipmentBase* Equipment) override;

	UFUNCTION(BlueprintCallable)
	virtual void UnEquip(EEquipmentType EquipmentType) override;

public: // Character attribute.
	UPROPERTY(EditAnywhere, Category = "Character Attribute")
	float AttackValueBase = 1.f;

	UPROPERTY(EditAnywhere, Category = "Character Attribute")
	float DefenseValueBase = 1.f;

	UPROPERTY(EditAnywhere, Category = "Character Attribute")
	float AttackSpeedBase = 1.f;

	UPROPERTY(EditAnywhere, Category = "Character Attribute")
	float HealthBase = 100.f;

	UPROPERTY(EditAnywhere, Category = "Character Attribute")
	float ManaBase = 100.f;

	UPROPERTY(EditAnywhere, Category = "Character Attribute")
	float MoveSpeedBase = 500.f;

	float AttackValueTotal = 1.f;

	float DefenseValueTotal = 1.f;

	float AttackSpeedTotal = 1.f;

	float HealthTotal = 100.f;

	float ManaTotal = 100.f;

	float MoveSpeedTotal = 500.f;

	float CurAttackValue = 1.f;

	float CurDefenseValue = 1.f;

	float CurAttackSpeed = 1.f;

	float CurHealth = 100.f;

	float CurMana = 100.f;

	float CurMoveSpeed = 500.f;

protected:
	UFUNCTION()
	virtual void ReceiveDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* InstigatorController, AActor* DamageCauser);
};
