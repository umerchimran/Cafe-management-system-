#include "Customer.h"
#include "User.h"

Customer:: Customer () : User() {}

void Customer::CustomerMenu(MenuItem menu[], int& menuSize)
{
   
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