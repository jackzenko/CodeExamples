#include "Item.h"

std::string Item::GetName() const {
    return name;
}

HRESULT Item::SetName(std::string newName)
{
    name = newName;
    return S_OK;
}

float Item::GetPrice() const
{
    return price;
}

HRESULT Item::SetPrice(float newPrice)
{
    price = newPrice;
    return S_OK;
}

int Item::GetId()
{
    return id;
}

HRESULT Item::SetId(int newId)
{
    id = newId;
    return S_OK;
}
