#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpriteLandPlayerController.generated.h"

//UENUM(BlueprintType)
//enum class FControllState : uint8
//{
//
//};

UCLASS()
class SPRITELAND_API ASpriteLandPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASpriteLandPlayerController();

protected:
	virtual void BeginPlay() override;

protected:
	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RunAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* DodgeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* AttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* BackpackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SkillAction_1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SkillAction_2;

	UFUNCTION()
	void OnJumpButtonPressed();

	UFUNCTION()
	void OnJumpButtonReleased();

	UFUNCTION()
	void OnMoveButtonTriggered(const FInputActionValue& Value);

	UFUNCTION()
	void OnRunButtonPressed();

	UFUNCTION()
	void OnRunButtonReleased();

	UFUNCTION()
	void OnLookButtonTriggered(const FInputActionValue& Value);

	UFUNCTION()
	void OnDodgeButtonPressed();

	UFUNCTION()
	void OnAttackButtonPressed();

	UFUNCTION()
	void OnBackpackButtonPressed();

	UFUNCTION()
	void OnSkillButtonPressed_1();

	UFUNCTION()
	void OnSkillButtonPressed_2();

protected:
	UPROPERTY(EditDefaultsOnly)
	class UBackpackComponent* BackpackComponent;

	UPROPERTY()
	class ASpriteLandHUD* SpriteLandHUD;

protected: // Update health bar.
	class AEnemyCharacterBase* CurrentLockingTarget;

public:
	FORCEINLINE UBackpackComponent* GetBackpackComponent()
	{
		return BackpackComponent;
	}

	FORCEINLINE ASpriteLandHUD* GetSpriteLandHUD()
	{
		return SpriteLandHUD;
	}

	FORCEINLINE AEnemyCharacterBase* GetCurrentLockingTarget()
	{
		return CurrentLockingTarget;
	}
};
