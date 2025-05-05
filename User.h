// User.h
#ifndef USER_H
#define USER_H

#include "MenuItem.h"
#include "Order.h"
using namespace std;

class User
{
public:
    virtual void ADMIN_MENU(MenuItem menu[], int& menuSize) {
        // Default implementation for non-administrator users
        cout << "Not an administrator. Cannot access administrator menu.\n";
    }


    static const int MAX_USERS = 100;
    static const int MAX_ORDERS = 10;
    int UserID[MAX_USERS];
    string UserName[MAX_USERS];
    string Password[MAX_USERS];
    string UserType[MAX_USERS];
    Order OrderHistory[MAX_ORDERS];
    int numUsers;
    int numOrders;
    int loggedInUserIndex;

    static int OrderCounter;


public:
    User();
    ~User();

    void Register();
    void Login();
    void Logout();
    string GetUserType() const;
    void CustomerMenu(const MenuItem menu[], int menuSize);
    void cafe_staff(MenuItem menu[], int& menuSize);

    void AddMenuItem(MenuItem menu[], int& menuSize);
    void RemoveMenuItem(MenuItem menu[], int& menuSize);
    bool is_item_id_unique(const MenuItem menu[], int menuSize, int id);
    int find_item_index(const MenuItem menu[], int menuSize, int id);
    void rate(const MenuItem menu[], int& menuSize);
    void DisplayMenu(const MenuItem menu[], int menuSize) const;
    void PlaceOrder(const MenuItem menu[], int menuSize);
    void ViewOrderHistory(const MenuItem menu[], int menuSize) const;

    void manage_discount();


private:
    void LoadUserData();
    void SaveUserData();

};

#endif // USER_H
