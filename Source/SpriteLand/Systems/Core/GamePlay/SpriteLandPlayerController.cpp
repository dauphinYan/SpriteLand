#include "SpriteLandPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/BackpackComponent.h"
#include "SpriteLand/HUD/SpriteLandHUD.h"
#include "SpriteLand/HUD/Backpack/BackpackWidget.h"
#include "SpriteLand/Character/Type/Enemy/EnemyCharacterBase.h"
#include "SpriteLand/Interface/CharacterActionInterface.h"
#include "SpriteLand/Interface/SkillInterface.h"

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

	if (SpriteLandHUD == nullptr)
	{
		SpriteLandHUD = Cast<ASpriteLandHUD>(GetHUD());
	}

	BackpackComponent->PlayerController = this;
}

void ASpriteLandPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnJumpButtonPressed);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &ASpriteLandPlayerController::OnJumpButtonReleased);
		EnhancedInput->BindAction(DodgeAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnDodgeButtonPressed);
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASpriteLandPlayerController::OnMoveButtonTriggered);
		EnhancedInput->BindAction(RunAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnRunButtonPressed);
		//EnhancedInput->BindAction(RunAction, ETriggerEvent::Completed, this, &ASpriteLandPlayerController::OnRunButtonReleased);
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASpriteLandPlayerController::OnLookButtonTriggered);
		EnhancedInput->BindAction(AttackAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnAttackButtonPressed);
		EnhancedInput->BindAction(BackpackAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnBackpackButtonPressed);
		EnhancedInput->BindAction(SkillAction_1, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnSkillButtonPressed_1);
		EnhancedInput->BindAction(SkillAction_2, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnSkillButtonPressed_2);
	}
}

void ASpriteLandPlayerController::OnJumpButtonPressed()
{
	if (GetPawn() && GetPawn()->Implements<UCharacterActionInterface>())
	{
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

void ASpriteLandPlayerController::OnRunButtonPressed()
{
	if (GetPawn() && GetPawn()->Implements<UCharacterActionInterface>())
	{
		ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(GetPawn());
		if (Interface)
		{
			Interface->StartRunning();
		}
	}
}

void ASpriteLandPlayerController::OnRunButtonReleased()
{
	if (GetPawn() && GetPawn()->Implements<UCharacterActionInterface>())
	{
		ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(GetPawn());
		if (Interface)
		{
			Interface->StopRunning();
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

void ASpriteLandPlayerController::OnAttackButtonPressed()
{
	if (GetPawn() && GetPawn()->Implements<UCharacterActionInterface>())
	{
		ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(GetPawn());
		if (Interface)
		{
			Interface->Attack();
		}
	}
}

void ASpriteLandPlayerController::OnBackpackButtonPressed()
{
	if (SpriteLandHUD == nullptr)
	{
		SpriteLandHUD = Cast<ASpriteLandHUD>(GetHUD());
	}

	if (SpriteLandHUD)
	{
		if (SpriteLandHUD->SetBackpackView())
		{
			SetShowMouseCursor(true);
			FInputModeGameAndUI InputMode;
			InputMode.SetWidgetToFocus(SpriteLandHUD->GetBackpackWidget()->TakeWidget());
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			SetInputMode(InputMode);
		}
		else
		{
			SetShowMouseCursor(false);
			FInputModeGameOnly InputMode;
			SetInputMode(InputMode);
		}
	}

}

void ASpriteLandPlayerController::OnSkillButtonPressed_1()
{
	if (GetPawn() && GetPawn()->Implements<USkillInterface>())
	{
		ISkillInterface* Interface = Cast<ISkillInterface>(GetPawn());
		if (Interface)
		{
			Interface->UseSkillByButton(1);
		}
	}
}

void ASpriteLandPlayerController::OnSkillButtonPressed_2()
{

}
