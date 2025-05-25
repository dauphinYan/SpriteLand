#include "SpriteLandHUD.h"
#include "Backpack/BackpackWidget.h"
#include "Main/MainWidget.h"
#include "SpriteLand/Systems/Feature/SkillSystem/SkillInfo.h"

void ASpriteLandHUD::BeginPlay()
{
	Super::BeginPlay();

	if (BackpackWidgetClass)
	{
		APlayerController* PlayerController = GetOwningPlayerController();
		BackpackWidget = CreateWidget<UBackpackWidget>(PlayerController, BackpackWidgetClass);
	}

	if (MainWidgetClass)
	{
		APlayerController* PlayerController = GetOwningPlayerController();
		MainWidget = CreateWidget<UMainWidget>(PlayerController, MainWidgetClass);
		if (MainWidget)
		{
			MainWidget->AddToViewport();
		}
	}
}

bool ASpriteLandHUD::SetBackpackView()
{
	if (BackpackWidget == nullptr)
	{
		if (BackpackWidgetClass)
		{
			APlayerController* PlayerController = GetOwningPlayerController();
			BackpackWidget = CreateWidget<UBackpackWidget>(PlayerController, BackpackWidgetClass);
		}
	}

	if (BackpackWidget == nullptr) return false;

	if (BackpackWidget->IsInViewport())
	{
		BackpackWidget->RemoveFromViewport();
		return false;
	}
	else
	{
		BackpackWidget->AddToViewport();
		return true;
	}
}

void ASpriteLandHUD::InitializeBossHealthBar(FText BossName, float HealthPercent)
{
	if (MainWidget)
	{
		MainWidget->InitializeBossHealthBar(BossName, HealthPercent);
	}
}

void ASpriteLandHUD::UpdateBossHealthBar(float HealthPercent)
{
	if (MainWidget)
	{
		MainWidget->UpdateBossHealthBar(HealthPercent);
	}
}

void ASpriteLandHUD::HideBossHealthBar()
{
	if (MainWidget)
	{
		MainWidget->HideBossHealthBar();
	}
}

void ASpriteLandHUD::UpdateCharacterHealthBar(float CurHealth, float TotalHealth)
{
	if (MainWidget)
	{
		MainWidget->UpdateHeroHealthBar(CurHealth, TotalHealth);
	}
}

void ASpriteLandHUD::UpdateCharacterManaBar(float CurMana, float TotalMana)
{
	if (MainWidget)
	{
		MainWidget->UpdateHeroManaBar(CurMana, TotalMana);
	}
}

void ASpriteLandHUD::UpdateHeroSkillData(TArray<FSkillData> SkillDatas)
{
	if (MainWidget)
	{
		MainWidget->UpdateHeroSkillData(SkillDatas);
	}
}

void ASpriteLandHUD::UseSkill(FGameplayTag SkillNameTag)
{
	if (MainWidget)
	{
		MainWidget->UseSkill(SkillNameTag);
	}
}

void ASpriteLandHUD::AddCombo()
{
	if (MainWidget)
	{
		MainWidget->AddCombo();
	}
}

void ASpriteLandHUD::LockingTarget(FVector2D& InScreenPosition)
{
	if (LockOnMarkWidget == nullptr)
	{
		LockOnMarkWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), LockOnMarkWidgetClass);
		LockOnMarkWidget->AddToViewport();
	}

	if (LockOnMarkWidget)
	{
		LockOnMarkWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
		FVector2D ScreenPosition = InScreenPosition - LockOnMarkWidget->GetDesiredSize() / 2;
		LockOnMarkWidget->SetPositionInViewport(ScreenPosition);
	}
}