#include "SpriteLandPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/BackpackComponent.h"

ASpriteLandPlayerController::ASpriteLandPlayerController()
{
	BackpackComponent = CreateDefaultSubobject<UBackpackComponent>(TEXT("Backpack Component"));
}

void ASpriteLandPlayerController::BeginPlay()
{
	Super::BeginPlay();


}

void ASpriteLandPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Jump
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnJumpButtonPressed);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &ASpriteLandPlayerController::OnJumpButtonReleased);

		// Dodget
		EnhancedInput->BindAction(DodgetAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnDodgeButtonPressed);

		// Moving
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASpriteLandPlayerController::OnMoveButtonPressed);

		// Looking
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASpriteLandPlayerController::OnLookTriggered);
	}


}

void ASpriteLandPlayerController::OnJumpButtonPressed()
{

}

void ASpriteLandPlayerController::OnJumpButtonReleased()
{
}

void ASpriteLandPlayerController::OnMoveButtonPressed(const FInputActionValue& Value)
{
}

void ASpriteLandPlayerController::OnLookTriggered(const FInputActionValue& Value)
{
}

void ASpriteLandPlayerController::OnDodgeButtonPressed(const FInputActionValue& Value)
{
}
