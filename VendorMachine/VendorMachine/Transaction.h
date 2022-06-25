#pragma once

#include "Item.h"

class Transaction {
public:
    int time;
    int itemId;
    std::string itemName;
    float itemPrice;

    std::string toString();
    void print();
};