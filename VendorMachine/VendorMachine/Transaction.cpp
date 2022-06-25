#include "Transaction.h"

std::string Transaction::toString()
{
    std::string output = 
        std::to_string(time) 
        + " " 
        + std::to_string(itemId) 
        + " " 
        + itemName 
        + " " 
        + std::to_string(itemPrice);
    return output;
}

void Transaction::print()
{
}
