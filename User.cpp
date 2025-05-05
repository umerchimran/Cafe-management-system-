
#include "User.h"
using namespace std;

int User::OrderCounter = 1;

User::User() : numUsers(0), numOrders(0), loggedInUserIndex(-1)
{
    LoadUserData();
}

User::~User() {
    SaveUserData();
}

void User::Register()
{
    // Implementation of Register method
    if (numUsers < MAX_USERS)
    {
        cout << "ENTER USERNAME: ";
        cin >> UserName[numUsers];
        cout << endl;
        cout << "ENTER PASSWORD:: ";
        cin >> Password[numUsers];
        cout << endl;
        cout << "ENTER USERTYPE: (customer/cafe_staff (staff)/administrator (admin): ";
        cin >> UserType[numUsers];
        cout << endl;
        UserID[numUsers] = numUsers + 1;
        numUsers++;

        cout << "REGISTERATION SUCCESSFULL\n";
    }
    else {
        cout << "MAXIMUM NUMBERS OF USER REACHED \n";
    }
}

void User::Login()
{
    // Implementation of Login method
    string username, password;
    cout << "ENTER USERNAME: ";
    cin >> username;
    cout << endl;
    cout << "ENTER PASSWORD ";
    cin >> password;
    cout << endl;
    for (int i = 0; i < numUsers; ++i) {
        if (UserName[i] == username && Password[i] == password) {
            loggedInUserIndex = i;
            cout << "LOGIN SUCCESSFULL\n";
            return;
        }
    }
    cout << endl;
    cout << "LOGIN FAILED. ERROR!\n";
}

void User::Logout()
{
    // Implementation of Logout method
    loggedInUserIndex = -1;
    cout << "LOGOUT SUCCESSFULL\n";

}

string User::GetUserType() const
{
    // Implementation of GetUserType method
    if (loggedInUserIndex != -1)
    {
        return UserType[loggedInUserIndex];
    }
    return "";
}

void User::CustomerMenu(const MenuItem menu[], int menuSize) {
    // Implementation of CustomerMenu method
    cout << ">> CUSTOMER MENU <<\n";
    cout << endl;
    cout << "1. View Menu\n";
    cout << "2. Place Order\n";
    cout << "3. View Order History\n";
    cout << "4. Rate Item\n";
    cout << "5. logout \n";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        DisplayMenu(menu, menuSize);
        break;
    case 2:
        PlaceOrder(menu, menuSize);
        break;
    case 3:
        ViewOrderHistory(menu, menuSize);
        break;
    case 4:
        rate(menu, menuSize);
        break;
    case 5:
        cout << "loged out\n";
        break;
    default:
        cout << "Invalid choice.\n";
    }

}

void User::cafe_staff(MenuItem menu[], int& menuSize) { ////////////  for cafe _ staff
    // Implementation of cafe_staff method
    cout << ">> CAFE_STAFF MENU <<\n";
    cout << endl;
    cout << "1. View Menu\n";
    cout << "2. place order\n";
    cout << "3. Add Menu Item\n";
    cout << "4. Remove Menu Item\n";
    cout << "5. Logout\n";

    int choice;
    cin >> choice;

    switch (choice) {
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
        cout << "Logged out\n";
        break;
    default:
        cout << "Invalid choice.\n";
    }
}

void User::manage_discount()
{
    const double disc = 20.0;
    const double disc_per = 0.1;

    if (loggedInUserIndex != -1) {
        Order& currentOrder = OrderHistory[numOrders - 1];
        double totalCost = currentOrder.GetTotalPrice();

        if (totalCost > disc) {
            double discountAmount = totalCost * disc_per;
            double discountedPrice = totalCost - discountAmount;

            cout << "CONGRATULATION . YOU GOT A DISCOUNT OF $" << discountAmount << ".\n";
            cout << "DISCOUNTED PRICE $" << discountedPrice << "\n";
        }
        else {
            cout << "NO DISCOUNT AVAILABLE FOR THE CURRENT ORDER\n";
        }
    }
    else {
        cout << "NOT LOGGED IN\n";
    }
}
void User::AddMenuItem(MenuItem menu[], int& menuSize) {
    // Implementation of AddMenuItem method
    if (menuSize < MenuItem::MAX_ITEMS) {
        int id;
        string name, description;
        double price;
        int quantity;

        cout << "ENTER ITEM ID: ";
        cin >> id;

        // Check if the ID is unique
        if (is_item_id_unique(menu, menuSize, id)) {
            cout << "ENTER ITEM NAME: ";
            cin >> name;

            cout << "ENTER ITEM DESCRIPTION: ";
            cin >> description;

            cout << "ENTER PRICE: ";
            cin >> price;

            cout << "ENTER QUANTITY IN STOCK: ";
            cin >> quantity;

            menu[menuSize++] = MenuItem(id, name, description, price, quantity);
            cout << "MENU ITEM ADDED SUCCESSFULLY\n";
        }
        else {
            cout << "ITEM ID MUST BE A UNIQUE NUM .ITEM NOT ADDED\n";
        }
    }
    else {
        cout << "MAXIMUN  NUMBER OF ITEM MENU REACHED . COULD NOT ADD MORE ITEMS\n";
    }
}

void User::RemoveMenuItem(MenuItem menu[], int& menuSize) {
    // Implementation of RemoveMenuItem method
    int id;
    cout << "ENTER THE ITEM ID TO REMOVE: ";
    cin >> id;

    int index = find_item_index(menu, menuSize, id);

    if (index != -1) {
        // Shift the array to remove the item
        for (int i = index; i < menuSize - 1; ++i) {
            menu[i] = menu[i + 1];
        }

        // Decrement menuSize to reflect the removed item
        --menuSize;

        cout << "MENU ITEM REMOVED SUCCESSFULLY\n";
    }
    else {
        cout << "ITEM NOT FOUND, CANNOT REMOVE: \n";
    }

}

bool User::is_item_id_unique(const MenuItem menu[], int menuSize, int id)
{
    // Implementation of IsItemIDUnique method
    for (int i = 0; i < menuSize; ++i) {
        if (menu[i].GetItemID() == id) {
            return false; // ID is not unique
        }
    }
    return true; // ID is unique
}

int User::find_item_index(const MenuItem menu[], int menuSize, int id)
{
    // Implementation of FindMenuItemIndex method
    for (int i = 0; i < menuSize; ++i) {
        if (menu[i].GetItemID() == id) {
            return i; // Found the item, return its index
        }
    }
    return -1; // Item not found
}

void User::rate(const MenuItem menu[], int& menuSize) {
    // Implementation of rate method
    int id;
    cout << "ENTER ITEM ID TO RATE:  ";
    cin >> id;

    int index = find_item_index(menu, menuSize, id);
    if (index != -1) {
        double rating;
        cout << "ENTER RATING BETWEEN (between 1 and 5): ";
        cin >> rating;

        // Validate the rating
        if (rating >= 1.0 && rating <= 5.0) {

            cout << "ITEM RATED SUCCESSFULLY\n";
        }
        else {
            cout << "INVALID RATING . PLEASE RATE BETWEEN 1 - 5\n";
        }
    }
    else {
        cout << "ITEM NOT FOUND . CANNOT RATE.\n";
    }
}

void User::DisplayMenu(const MenuItem menu[], int menuSize) const
{
    // Implementation of DisplayMenu method
    cout << ">> MENU <<\n";
    for (int i = 0; i < menuSize; ++i) {
        menu[i].DisplayItem();
        cout << ">>------------------------->>\n";
    }
}

void User::PlaceOrder(const MenuItem menu[], int menuSize) {
    // Implementation of PlaceOrder method
    if (numOrders < MAX_ORDERS) {
        Order& currentOrder = OrderHistory[numOrders++];
        int choice;

        do {
            cout << "Menu:\n";
            for (int i = 0; i < menuSize; ++i) {
                cout << i + 1 << ". ";
                menu[i].DisplayItem();
                cout << ">>-------------------------<<\n";
            }

            cout << "ENTER ITEM ID TO ADD YOUR ORDER (0 TO FINISH): ";
            cin >> choice;

            if (choice > 0 && choice <= menuSize) {
                // Subtract 1 to get the correct index in the menu array
                currentOrder.AddItem(menu[choice - 1].GetItemID(), menu, menuSize);
            }
            else if (choice != 0) {
                cout << "Invalid choice. Please enter a valid item number or 0 to finish.\n";
            }

        } while (choice != 0);

        cout << "ORDER PLACED SUCCESSFULLY \n";
    }
    else {
        cout << "Maximum number of orders reached. Cannot place more orders.\n";
    }
}

void User::ViewOrderHistory(const MenuItem menu[], int menuSize) const {
    // Implementation of ViewOrderHistory method
    cout << "Order History:\n";
    for (int i = 0; i < numOrders; ++i) {
        OrderHistory[i].DisplayOrder(menu, menuSize);
        cout << ">>-------------------------<<\n";
    }
}

void User::LoadUserData() {
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

void User::SaveUserData()
{
    // Implementation of SaveUserData method
    ofstream file("users.txt");
    if (file.is_open()) {
        for (int i = 0; i < numUsers; ++i) {
            file << UserID[i] << " " << UserName[i] << " "
                << Password[i] << " " << UserType[i] << "\n";
        }
        file.close();
    }

}
