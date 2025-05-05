// MenuItem.cpp
#include "MenuItem.h"
using namespace std;


const int MenuItem::MAX_ITEMS;

MenuItem::MenuItem() : ItemID(0), ItemName(""), ItemDescription(""), Price(0.0), QuantityInStock(0) {}

MenuItem::MenuItem(int id, const  string& name, const  string& description, double price, int quantity)
    :ItemID(id), ItemName(name), ItemDescription(description), Price(price),
    QuantityInStock(quantity) {}

void MenuItem::DisplayItem() const
{
    cout << "ITEM ID: " << ItemID << "\n";
    cout << "ITEM NAME: " << ItemName << "\n";
    cout << "DESCRIPTIION " << ItemDescription << "\n";
    cout << "PRICE:$" << Price << "\n";
    cout << "QUANTITY IN STOCK " << QuantityInStock << "\n";
}

void MenuItem::UpdateStock(int quantity) const
{
    const_cast<MenuItem*>(this)->QuantityInStock += quantity;
    cout << "STOCK UPDATED SUCCESFULLY\n";
}

int MenuItem::GetItemID() const
{
    return ItemID;
}

double MenuItem::GetPrice() const
{
    return Price;
}

int MenuItem::GetQuantityInStock() const
{
    return QuantityInStock;
}

void MenuItem::SaveMenu(const MenuItem menu[], int menuSize) {
    ofstream file("menu.txt");
    if (file.is_open()) {
        for (int i = 0; i < menuSize; ++i) {
            file << menu[i].ItemID << " " << menu[i].ItemName << " " << menu[i].ItemDescription
                << " " << menu[i].Price << " " << menu[i].QuantityInStock << "\n";
        }
        file.close();
        cout << "\n";
    }
}

void MenuItem::LoadMenu(MenuItem menu[], int& menuSize) {
    ifstream file("menu.txt");
    menuSize = 0;
    if (file.is_open()) {
        while (file >> menu[menuSize].ItemID >> menu[menuSize].ItemName >> menu[menuSize].ItemDescription
            >> menu[menuSize].Price >> menu[menuSize].QuantityInStock) {
            ++menuSize;
            if (menuSize >= MAX_ITEMS) {
                cout << "MAXIMUM NUMBERS OF ITEMS REACHED\n";
                break;
            }
        }
        file.close();
    }
}
