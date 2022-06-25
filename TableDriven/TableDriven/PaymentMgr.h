#pragma once
#include "PaymentVisa.h"
#include "PaymentMaster.h"

using PAY_FUNC = bool(*)(float);

struct PAY_INFO {
    int paymentId;
    PAY_FUNC payFunc;
};

class PaymentMgr {
private:
    constexpr static PAY_INFO paymentTable[] = {
        {0, PayByVisa},
        {1, PayByMaster},
    };

    template<typename T>
    static int length(T& arr) {
        return sizeof(arr) / sizeof(arr[0]);
    }
public:
    static bool ProcessPayment(int paymentIdx, float price);
};

