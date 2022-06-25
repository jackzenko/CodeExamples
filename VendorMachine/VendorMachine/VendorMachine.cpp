
#include "VendorMachine.h"
#include <iostream>

VendorMachine::VendorMachine() {
    paymentMgr = make_unique<PaymentMgr>();
    statusMgr = make_unique<StatusMgr>();
    storageMgr = make_unique<StorageMgr>();
}

VendorMachine::~VendorMachine()
{
}

void VendorMachine::SetPaymentMgr(unique_ptr<PaymentMgr> newMgr)
{
    paymentMgr = move(newMgr);
}

void VendorMachine::SetStatusMgr(unique_ptr<StatusMgr> newMgr)
{
    statusMgr = move(newMgr);
}

void VendorMachine::SetStorageMgr(unique_ptr<StorageMgr> newMgr)
{
    storageMgr = move(newMgr);
}

HRESULT VendorMachine::Init()
{
    statusMgr->Init();
    return S_OK;
}

HRESULT VendorMachine::Run()
{

}
