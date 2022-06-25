
#include <vector>
#include "VendorMachine.h"
#include "afxwin.h"

int main()
{
    // vector<vector<int>> nums{{22, 22}, {22, 22}, {22, 22}};
    // vector<int> nums{ 22, 22, 22, 22, 22};

    auto machine = VendorMachine();
    int remainingCap = machine.GetRemainingCapacity();
    std::vector<std::unique_ptr<Item>> remainingItems = machine.GetRemainingItems();
    std::vector<std::unique_ptr<Item>> items;
    machine.Resupply(items);
    int cash = machine.CollectCash();
    

    return 0;
}