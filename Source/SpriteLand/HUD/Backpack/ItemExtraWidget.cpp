#include "ItemExtraWidget.h"
#include "Components/TextBlock.h"

void UItemExtraWidget::UpdateInfo(FText Des, FText Value)
{
	DesText->SetText(Des);
	ValueText->SetText(Value);
}
