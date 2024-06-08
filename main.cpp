#include <iostream>
#include <iomanip>
#include <string>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

using namespace std;

void ExecuteMenu(char option, ShoppingCart& theCart) {

    if (option == 'a') {
        string name, description;
        int price, quantity;
        cout << "ADD ITEM TO CART" << endl;
        cout << "Enter the item name:" << endl;
        getline(cin, name);
        cout << "Enter the item description:" << endl;
        getline(cin, description);
        cout << "Enter the item price:" << endl;
        cin >> price;
        cout << "Enter the item quantity:" << endl;
        cout << endl;
        cin >> quantity;
        cin.ignore();
        ItemToPurchase item(name, description, price, quantity);
        theCart.AddItem(item);
    } 
    
    else if (option == 'd') {
        string name;
        cout << "REMOVE ITEM FROM CART";
        cout << endl << "Enter name of item to remove:" << endl;
        getline(cin, name);
        theCart.RemoveItem(name);
    }

    else if (option == 'c') {
        string name;
        int quantity;
        cout << "CHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name:" << endl;
        getline(cin, name);
        cout << "Enter the new quantity:" << endl;
        cin >> quantity;
        cin.ignore();
        ItemToPurchase item(name, "none", 0, quantity);
        theCart.ModifyItem(item);
    }

    else if (option == 'i') {
        theCart.PrintDescriptions();
        cout << endl;
    }

    else if (option == 'o') {
        theCart.PrintTotal();
    }

}

// function to print menu
void PrintMenu() {
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
}

int main() {
    string customerName;
    string currentDate;

    
    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);

    cout << "Enter today's date:" << endl;
    getline(cin, currentDate);
    cout << endl;

    // creates shopping cart
    ShoppingCart cart(customerName, currentDate);

    // displays customer details
    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl;
    cout << endl;

    char option = ' ';
    while (option != 'q') {
        PrintMenu();

        do {
            cout << "Choose an option:" << endl;
            cin >> option;
            cin.ignore();
            // if its invalid instead of repeating menu it reprompts for choose an option
            if (option != 'a' && option != 'd' && option != 'c' && option != 'i' && option != 'o' && option != 'q') { 
                continue;
            }
        }
        while (option != 'a' && option != 'd' && option != 'c' && option != 'i' && option != 'o' && option != 'q');

        // executes the menu option
        if (option != 'q') {
            ExecuteMenu(option, cart);
        }
        }
    return 0;
}
