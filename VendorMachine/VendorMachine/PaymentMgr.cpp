#include <iostream>
#include "PaymentMgr.h"

HRESULT PaymentMgr::ProcessPayment(int idx, float price)
{
    constexpr int tableSize = sizeof(payTable) / sizeof(payTable[0]);
    for (int i = 0; i < tableSize; ++i) {
        if (payTable[i].idx == idx && payTable[i].payFunc != nullptr) {
            return payTable[i].payFunc(price);
        }
    }
    return E_FAIL;
}
