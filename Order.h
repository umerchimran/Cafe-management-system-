
#ifndef ORDER_H
#define ORDER_H

#include "MenuItem.h"
using namespace std;

class Order
{
private:
    static const int MAX_ITEMS = 20;
    int OrderID;
    int CustomerID;
    int ItemsOrdered[MAX_ITEMS];
    double TotalPrice;
    string OrderStatus;

public:
    Order();
    Order(int orderId, int customerId);
    double GetTotalPrice();
    void AddItem(int itemID, const MenuItem menu[], int menuSize);
    void DisplayOrder(const MenuItem menu[], int menuSize) const;
};

#endif // ORDER_H