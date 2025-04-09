#include "BackpackWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WrapBox.h"
#include "BackpackItemWidget.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/BackpackComponent.h"
#include "SpriteLand/Systems/Core/GamePlay/SpriteLandPlayerController.h"

void UBackpackWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	InitializeItemInfoCache();
}

void UBackpackWidget::NativeConstruct()
{
	Super::NativeConstruct();

	PlayerController = Cast<ASpriteLandPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (PlayerController != nullptr)
	{
		BackpackComponent = PlayerController->GetBackpackComponent();
	}

	UpdateBackpackView();
}

void UBackpackWidget::InitializeItemInfoCache()
{
	auto LoadTable = [&](UDataTable* Table)
		{
			if (!Table) return;

			static const FString ContextString(TEXT("ItemInfoCache"));

			for (auto& RowName : Table->GetRowNames())
			{
				if (FItemInfoBase* Row = Table->FindRow<FItemInfoBase>(RowName, ContextString))
				{
					ItemInfoCache.Add(Row->ItemName, Row);
				}
			}
		};

	LoadTable(EquipmentDataTable);
	LoadTable(UsableDataTable);
}

void UBackpackWidget::UpdateBackpackView()
{
	if (!BackpackComponent) return;

	const TMap<EItemName, int32>& Items = BackpackComponent->GetItems();
	ItemWrapBox->ClearChildren();

	for (const auto& Pair : Items)
	{
		EItemName ItemName = Pair.Key;
		int32 Count = Pair.Value;

		FItemInfoBase** InfoPtr = ItemInfoCache.Find(ItemName);
		if (!InfoPtr) continue;

		const FItemInfoBase* Info = *InfoPtr;

		UBackpackItemWidget* ItemWidget = CreateWidget<UBackpackItemWidget>(this, ItemWidgetClass);
		ItemWrapBox->AddChildToWrapBox(ItemWidget);
	}
}

FItemInfoBase* UBackpackWidget::FindItemInfoInTables(EItemName ItemName)
{
	return nullptr;
}
