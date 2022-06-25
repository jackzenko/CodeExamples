#pragma once
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <vector>
#include <memory>
#include <list>
#include "afxwin.h"
#include "Item.h"
#include "Transaction.h"
#include "PaymentMgr.h"
#include "StatusMgr.h"
#include "StorageMgr.h"
#include "Logger.h"

using namespace std;

class VendorMachine {
private:
    unique_ptr<PaymentMgr> paymentMgr;
    unique_ptr<StatusMgr> statusMgr;
    unique_ptr<StorageMgr> storageMgr;
    Logger logger;
public:
    VendorMachine();
    ~VendorMachine();
    void SetPaymentMgr(unique_ptr<PaymentMgr> newMgr);
    void SetStatusMgr(unique_ptr<StatusMgr> newMgr);
    void SetStorageMgr(unique_ptr<StorageMgr> newMgr);
    HRESULT Init();
    HRESULT Run();


    /*using StorageCellType = std::pair<Item, int>();
    using StorageType = std::vector<std::unique_ptr<std::pair<Item, int>>>;
private:
    int storageSize;
    int storageDepth;
    float cash;
    StorageType storage;
    std::list<std::unique_ptr<Transaction>> transactions;

    bool ItemIsAvailable(int idx);
public:
    VendorMachine() : storageSize(0), storageDepth(0), cash(0), storage() , transactions() {};
    ~VendorMachine() {}
    HRESULT Init();
    HRESULT Run();
    HRESULT GetRemainingItems(std::shared_ptr<StorageType> items);
    int GetStorageSize();
    int GetStorageDepth();
    HRESULT Resupply(StorageType& items);
    int CollectCash();
    HRESULT SetCash(int cash);
    HRESULT GetTrasactions(std::string& output) const;
    HRESULT SaveMachineState();
    HRESULT LoadMachineState() const;
    HRESULT SetPrice(int key, float newPrice);
    HRESULT Sell(int itemIdx, int paymentIdx);*/
};