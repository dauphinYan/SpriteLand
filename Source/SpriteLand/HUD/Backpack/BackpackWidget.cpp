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

	const TArray<FItemStack>& Items = BackpackComponent->GetItems();
	ItemWrapBox->ClearChildren();

	for (const auto& Stack : Items)
	{
		EItemName ItemName = Stack.ItemName;
		int32 Count = Stack.Count;

		FItemInfoBase** InfoPtr = ItemInfoCache.Find(ItemName);
		if (!InfoPtr) continue;

		const FItemInfoBase* Info = *InfoPtr;

		UBackpackItemWidget* ItemWidget = CreateWidget<UBackpackItemWidget>(this, ItemWidgetClass);
		ItemWidget->UpdateViewInfo(Info, Count);
		ItemWrapBox->AddChildToWrapBox(ItemWidget);
	}
}

FItemInfoBase* UBackpackWidget::FindItemInfoInTables(EItemName ItemName)
{
	return nullptr;
}