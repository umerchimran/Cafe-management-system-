// MenuItem.h
#ifndef MENU_ITEM_H
#define MENU_ITEM_H
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>

class MenuItem
{
private:
    int ItemID;
    string ItemName;
    string ItemDescription;
    double Price;
    int QuantityInStock;

public:

    static const int MAX_ITEMS = 10;

    MenuItem();
    MenuItem(int id, const  string& name, const  string& description, double price, int quantity);

    void DisplayItem() const;
    void UpdateStock(int quantity) const;

    int GetItemID() const;
    double GetPrice() const;
    int GetQuantityInStock() const;

    static void SaveMenu(const MenuItem menu[], int menuSize);
    static void LoadMenu(MenuItem menu[], int& menuSize);
};

#endif // MENU_ITEM_H
