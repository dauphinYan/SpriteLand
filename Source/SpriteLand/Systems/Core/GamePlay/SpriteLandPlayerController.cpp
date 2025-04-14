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

	if (APlayerController* PC = Cast<APlayerController>(this))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ASpriteLandPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Jump
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnJumpButtonPressed);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &ASpriteLandPlayerController::OnJumpButtonReleased);

		// Dodge
		EnhancedInput->BindAction(DodgeAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnDodgeButtonPressed);

		// Moving
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASpriteLandPlayerController::OnMoveButtonTriggered);

		// Looking
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASpriteLandPlayerController::OnLookButtonTriggered);
	}
}

void ASpriteLandPlayerController::OnJumpButtonPressed()
{
	UE_LOG(LogTemp, Log, TEXT("JumpButtonDown."));
	if (GetPawn() && GetPawn()->Implements<UCharacterActionInterface>())
	{
		UE_LOG(LogTemp, Log, TEXT("Implement."));
		ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(GetPawn());
		if (Interface)
		{	
			Interface->JumpBegin();
		}
	}
}

void ASpriteLandPlayerController::OnJumpButtonReleased()
{

}

void ASpriteLandPlayerController::OnMoveButtonTriggered(const FInputActionValue& Value)
{
	if (GetPawn() && GetPawn()->Implements<UCharacterActionInterface>())
	{
		ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(GetPawn());
		if (Interface)
		{
			Interface->Move(Value);
		}
	}
}

void ASpriteLandPlayerController::OnLookButtonTriggered(const FInputActionValue& Value)
{
	if (GetPawn() && GetPawn()->Implements<UCharacterActionInterface>())
	{
		ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(GetPawn());
		if (Interface)
		{
			Interface->Look(Value);
		}
	}
}


void ASpriteLandPlayerController::OnDodgeButtonPressed()
{

}
