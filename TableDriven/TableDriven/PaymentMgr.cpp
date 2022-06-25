#include "PaymentMgr.h"

bool PaymentMgr::ProcessPayment(int paymentIdx, float price) {
    const int tableSize = length(paymentTable);
    for (int i = 0; i < tableSize; ++i) {
        if (paymentIdx == paymentTable[i].paymentId && paymentTable[i].payFunc != nullptr) {
            return paymentTable[i].payFunc(price);
        }
    }
    return false;
}

