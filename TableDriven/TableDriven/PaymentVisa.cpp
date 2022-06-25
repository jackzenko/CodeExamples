#include <iostream>
#include <string>
#include "PaymentVisa.h"

bool PayByVisa(float price)
{
    std::cout << "PayByVisa(float price " + std::to_string(price) + ") called" << std::endl;
    return true;
}
