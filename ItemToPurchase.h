#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price, int quantity);

    void SetName(string name);
    void SetDescription(string description);
    void SetPrice(int price);
    void SetQuantity(int quantity);

    
    int GetPrice() const;
    int GetQuantity() const;

    void PrintItemCost() const;
    void PrintItemDescription() const;

    string GetName() const;
    string GetDescription() const;

private:
    int itemPrice;
    int itemQuantity;
    string itemName;
    string itemDescription;

};

#endif
