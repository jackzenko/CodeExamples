#include "PaymentMgr.h"

int main() {
    float price = 10.5;
    int paymentIdx = 1;
    bool result = PaymentMgr::ProcessPayment(paymentIdx, price);
}

