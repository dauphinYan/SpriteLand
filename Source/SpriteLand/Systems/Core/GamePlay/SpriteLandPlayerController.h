#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpriteLand/Interface/CharacterActionInterface.h"
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
	UInputAction* DodgeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* AttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* BackpackAction;

	UFUNCTION()
	void OnJumpButtonPressed();

	UFUNCTION()
	void OnJumpButtonReleased();

	UFUNCTION()
	void OnMoveButtonTriggered(const FInputActionValue& Value);

	UFUNCTION()
	void OnLookButtonTriggered(const FInputActionValue& Value);

	UFUNCTION()
	void OnDodgeButtonPressed();

	UFUNCTION()
	void OnAttackButtonPressed();

	UFUNCTION()
	void OnBackpackButtonPressed();

protected:
	UPROPERTY(EditDefaultsOnly)
	class UBackpackComponent* BackpackComponent;

	UPROPERTY()
	class ASpriteLandHUD* SpriteLandHUD;

public:
	FORCEINLINE UBackpackComponent* GetBackpackComponent()
	{
		return BackpackComponent;
	}
};
