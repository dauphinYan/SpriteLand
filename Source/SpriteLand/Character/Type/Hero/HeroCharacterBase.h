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

	UPROPERTY(EditDefaultsOnly)
	class UEquipmentComponent* EquipmentComponent;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AWeaponBase> WeaponClass;

	UPROPERTY(EditDefaultsOnly)
	class UAnimMontage* DodgeMontage;

protected:
	virtual void Move(const struct FInputActionValue& Value) override;

	virtual void Look(const FInputActionValue& Value) override;

	virtual void Dodge() override;

	virtual void JumpBegin() override;

	UFUNCTION(BlueprintCallable)
	void Equip();
};
