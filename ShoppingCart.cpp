#include "ShoppingCart.h"
#include <iostream>
using namespace std;

ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

string ShoppingCart::GetCustomerName() const {
    return customerName;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}

string ShoppingCart::GetDate() const {
    return currentDate;
}


void ShoppingCart::RemoveItem(string name) {
    bool found = false;
    for (unsigned i = 0; i < cartItems.size(); ++i) {
        if (cartItems.at(i).GetName() == name) {
            cartItems.erase(cartItems.begin() + i);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found in cart. Nothing removed." << endl;
        //cout << endl;
    }
    cout << endl;
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
    bool found = false;
    for (unsigned i = 0; i < cartItems.size(); ++i) {
        if (cartItems.at(i).GetName() == item.GetName()) {
            if (item.GetDescription() != "none") {
                cartItems.at(i).SetDescription(item.GetDescription());
            }
            if (item.GetPrice() != 0) {
                cartItems.at(i).SetPrice(item.GetPrice());
            }
            if (item.GetQuantity() != 0) {
                cartItems.at(i).SetQuantity(item.GetQuantity());
            }
            found = true;
            break;
        }
    }
    if (!found) {
    cout << "Item not found in cart. Nothing modified." << endl;
    //cout << endl;
    }
    cout << endl;
}



int ShoppingCart::GetCostOfCart() const {
    int totalCost = 0;
    for (unsigned i = 0; i < cartItems.size(); ++i) {
        totalCost += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
    }
    return totalCost;
}

int ShoppingCart::GetNumItemsInCart() const {
    int totalQuantity = 0;
    for (unsigned i = 0; i < cartItems.size(); ++i) {
        totalQuantity += cartItems.at(i).GetQuantity();
    }
    return totalQuantity;
}

void ShoppingCart::PrintDescriptions() const {
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << endl;
    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    } else {
        cout << "Item Descriptions" << endl;
        for (unsigned i = 0; i < cartItems.size(); ++i) {
            cartItems.at(i).PrintItemDescription();
        }
    }
}

void ShoppingCart::PrintTotal() const {
    cout << "OUTPUT SHOPPING CART" << endl;
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl;
    cout << endl;
    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
        //cout << endl;
    } else {
        for (unsigned i = 0; i < cartItems.size(); ++i) {
            cartItems.at(i).PrintItemCost();
        }
    }
    
    cout << endl << "Total: $" << GetCostOfCart() << endl;
    cout << endl;
}

