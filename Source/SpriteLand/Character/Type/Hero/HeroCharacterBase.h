#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpriteLand/Interface/CharacterActionInterface.h"
#include "SpriteLand/Interface/BuffInterface.h"
#include "SpriteLand/Interface/SkillInterface.h"
#include "HeroCharacterBase.generated.h"

UCLASS()
class SPRITELAND_API AHeroCharacterBase : public ACharacter, public ICharacterActionInterface, public IBuffInterface, public ISkillInterface
{
	GENERATED_BODY()

	friend class UHeroSkillComponent;

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UHeroBuffComponent* BuffComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UHeroSkillComponent* SkillComponent;

	UPROPERTY()
	class ASpriteLandPlayerController* PlayerController;

	UPROPERTY(EditDefaultsOnly)
	class UAnimMontage* DodgeMontage;

protected:
	virtual void Move(const struct FInputActionValue& Value) override;

	virtual void Look(const FInputActionValue& Value) override;

	virtual void StartRunning() override;

	virtual void StopRunning() override;

	virtual void Dodge() override;

	virtual void JumpBegin() override;

	virtual void Attack() override;

	UFUNCTION(BlueprintCallable)
	virtual void Equip(AEquipmentBase* Equipment) override;

	UFUNCTION(BlueprintCallable)
	virtual void UnEquip(EEquipmentType EquipmentType) override;

	UPROPERTY(BlueprintReadWrite)
	bool bCanMove = true;

	UPROPERTY(EditDefaultsOnly)
	float WalkSpeed = 300.f;

	UPROPERTY(EditDefaultsOnly)
	float RunSpeed = 500.f;

	bool bIsRunning = false;

public:
	void SetCanMove(bool InbCanMove);

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

	virtual void RestoreHealth(float InValue) override;

	virtual void RestoreMana(float InValue);

protected: // Skill
	virtual bool UseSkill(FGameplayTag SkillNameTag) override;

	virtual bool UpgradeSkill(FGameplayTag SkillNameTag) override;

	virtual bool UseSkillByButton(int32 Index) override;

public:
	FORCEINLINE UHeroSkillComponent* GetSkillComponent()
	{
		return SkillComponent;
	}
	FORCEINLINE UEquipmentComponent* GetEquipmentComponent()
	{
		return EquipmentComponent;
	}
};
