#include <iostream>
#include <string>
#include "PaymentMaster.h"

bool PayByMaster(float price)
{
    std::cout << "PayByMaster(float price " + std::to_string(price) + ") called" << std::endl;
    return true;
}
