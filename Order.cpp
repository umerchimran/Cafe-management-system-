
#include "Order.h"
using namespace std;


const int Order::MAX_ITEMS;

Order::Order() : OrderID(-1), CustomerID(-1), TotalPrice(0), OrderStatus("Pending")
{
    for (int i = 0; i < MAX_ITEMS; ++i)
    {
        ItemsOrdered[i] = -1;
    }
}

double Order::GetTotalPrice()
{
    return TotalPrice;
}
Order::Order(int orderId, int customerId)
    : OrderID(orderId), CustomerID(customerId), TotalPrice(0), OrderStatus("Pending")
{
    for (int i = 0; i < MAX_ITEMS; ++i)
    {
        ItemsOrdered[i] = -1;
    }
}

void Order::AddItem(int itemID, const MenuItem menu[], int menuSize)
{
    // Find the menu item with the given ID
    for (int i = 0; i < menuSize; ++i) {
        if (menu[i].GetItemID() == itemID) {
            // Check if the item is in stock
            if (menu[i].GetQuantityInStock() > 0) {
                // Find the first empty slot in the order
                for (int j = 0; j < MAX_ITEMS; ++j) {
                    if (ItemsOrdered[j] == -1) {
                        ItemsOrdered[j] = itemID;
                        TotalPrice += menu[i].GetPrice();
                        menu[i].UpdateStock(-1);  // Reduce the stock of the item///////////
                        cout << "ITEAM ADDED TO THE ORDER .\n";
                        return;
                    }
                }
                cout << "ORDER IS FULL . CANNOT ADD MORE \n";
            }
            else {
                cout << "ITEM IS OUT OF STOCK.\n";
            }
            return;
        }
    }
    cout << "ITEM NOT FOUND \n";

}

void Order::DisplayOrder(const MenuItem menu[], int menuSize) const
{
    cout << "ORDER ID: " << OrderID << "\n";
    cout << "CUSTOMER ID: " << CustomerID << "\n";
    cout << "ITEMS ORDERED:\n";
    for (int i = 0; i < MAX_ITEMS && ItemsOrdered[i] != -1; ++i)
    {
        int itemID = ItemsOrdered[i];
        for (int j = 0; j < menuSize; ++j) {
            if (menu[j].GetItemID() == itemID) {
                menu[j].DisplayItem();
                cout << "-------------------------\n";
                break;
            }
        }
    }
    cout << "Total Price: $" << TotalPrice << "\n";
    cout << "Order Status: " << OrderStatus << "\n";


}
