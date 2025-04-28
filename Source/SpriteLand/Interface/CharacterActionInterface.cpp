#include "CharacterActionInterface.h"
#include "SpriteLand/Systems/Feature/EquipmentSystem/EquipmentBase.h"

void ICharacterActionInterface::Move(const FInputActionValue& Value)
{
}

void ICharacterActionInterface::Look(const FInputActionValue& Value)
{
}

void ICharacterActionInterface::Dodge()
{
}

void ICharacterActionInterface::JumpBegin()
{
}

void ICharacterActionInterface::Attack()
{

}

void ICharacterActionInterface::Equip(AEquipmentBase* Equipment)
{
}

void ICharacterActionInterface::UnEquip(EEquipmentType EquipmentType)
{
}