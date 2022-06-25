#pragma once
#include "afxwin.h"
#include "PaymentVisa.h"
#include "PaymentMaster.h"

using PAY_FUNC = HRESULT(*)(float);

typedef struct PAY_STRUCT
{
	int idx;
    PAY_FUNC payFunc;
};

class PaymentMgr {
public:
    constexpr static PAY_STRUCT payTable[] = {
        {0, PayByVisa},
        {1, PayByMaster},
    };
    static HRESULT ProcessPayment(int idx, float price);
};
