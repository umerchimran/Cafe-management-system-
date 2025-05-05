// Administrator.cpp
#include "Administrator.h"
#include "User.h"
using namespace std;


Administrator::Administrator() : User() {}

void Administrator::ADMIN_MENU(MenuItem menu[], int& menuSize)
{
    // Implementation of Administratormenu
    cout << "ADMINISTRATOR MENU:\n";
    cout << "1. View Menu\n";
    cout << "2. Place Order\n";
    cout << "3. Add Menu Item\n";
    cout << "4. Remove Menu Item\n";
    cout << "5. View Order history\n";
    cout << "6. Rate menu item\n";
    cout << "7. Any discount \n";
    cout << "8. View menu from file \n";
    cout << "9. View order from file \n";
    cout << "10.View users from file  \n";
    cout << "11.View ratings from file  \n";

    cout << "100. Logout\n";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        DisplayMenu(menu, menuSize);
        break;
    case 2:
        PlaceOrder(menu, menuSize);
        break;
    case 3:
        AddMenuItem(menu, menuSize);
        break;
    case 4:
        RemoveMenuItem(menu, menuSize);
        break;
    case 5:
        ViewOrderHistory(menu, menuSize);
        break;
    case 6:
        rate(menu, menuSize);
        break;

    case 7:
        manage_discount();
        break;
    case 8:
        LoadUserData();
        break;
    case 9:
        LoadUserData();
        break;

    default:
        cout << "Invalid choice.\n";
    }
}

void Administrator::AddMenuItem(MenuItem menu[], int& menuSize) {
    // Implementation of AddMenuItem method
    if (menuSize < MenuItem::MAX_ITEMS) {
        int id;
        string name, description;
        double price;
        int quantity;

        cout << "Enter Item ID: ";
        cin >> id;

        if (is_item_id_unique(menu, menuSize, id)) {
            cout << "Enter Item Name: ";
            cin >> name;

            cout << "Enter Item Description: ";
            cin >> description;

            cout << "Enter Price: ";
            cin >> price;

            cout << "Enter Quantity in Stock: ";
            cin >> quantity;

            menu[menuSize++] = MenuItem(id, name, description, price, quantity);
            cout << "Menu item added successfully.\n";
        }
        else {
            cout << "Item ID must be unique. Item not added.\n";
        }
    }
    else {
        cout << "Maximum number of menu items reached. Cannot add more items.\n";
    }
}

void Administrator::RemoveMenuItem(MenuItem menu[], int& menuSize) {
    // Implementation of RemoveMenuItem method
    int id;
    cout << "Enter Item ID to remove: ";
    cin >> id;

    int index = find_item_index(menu, menuSize, id);

    if (index != -1) {
        //  remove the item
        for (int i = index; i < menuSize - 1; ++i) {
            menu[i] = menu[i + 1];
        }

        // Decrement menuSize to reflect the removed item
        --menuSize;

        cout << "Menu item removed successfully.\n";
    }
    else {
        cout << "Item not found. Cannot remove.\n";
    }

}

void Administrator::LoadUserData() {
    // Implementation of LoadUserData method
    ifstream file("users.txt");
    if (file.is_open()) {
        while (file >> UserID[numUsers] >> UserName[numUsers] >> Password[numUsers] >> UserType[numUsers]) {
            numUsers++;
            if (numUsers >= MAX_USERS) {
                cout << "Maximum number of users reached.\n";
                break;
            }
        }
        file.close();
    }
}