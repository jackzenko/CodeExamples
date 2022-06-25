#pragma once
#include <string>
#include "afxwin.h"

class Item {
private:
    int id;
    float price;
    std::string name;

public:
    Item() : id(0), price(0), name("") {};
    Item(int i, float p, std::string n) : id(i), price(p), name(n) {};
    std::string GetName() const;
    HRESULT SetName(std::string newName);
    float GetPrice() const;
    HRESULT SetPrice(float newPrice);
    int GetId();
    HRESULT SetId(int newId);
};