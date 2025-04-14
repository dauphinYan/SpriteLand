#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpriteLand/Interface/CharacterActionInterface.h"
#include "SpriteLandPlayerController.generated.h"

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

protected:
	UPROPERTY(EditDefaultsOnly)
	class UBackpackComponent* BackpackComponent;

public:
	FORCEINLINE UBackpackComponent* GetBackpackComponent()
	{
		return BackpackComponent;
	}
};
