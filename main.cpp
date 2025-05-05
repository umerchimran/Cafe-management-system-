
#include "User.h"
#include "Administrator.h"

#include "Customer.h"

#include<iostream>
using namespace std;


int main()

{
    Administrator adminUser;

    cout << endl;
    cout << endl;

    cout << " >>>>> WELCOME TO CAFE MANAGEMENT SYSTEM <<<<<\n";
    MenuItem* cafeMenu = new MenuItem[50];
    int menuSize = 0;

    // Load the menu from the file
    MenuItem::LoadMenu(cafeMenu, menuSize);

    User userSystem;

    if (menuSize == 0)
    {
        // MENU ITEAMS IF EMPTY

// Fast Food


        cafeMenu[menuSize++] = MenuItem(000, "", ">>>>>>>>>>>>>>>>>>  FAST FOOD  >>>>>>>>>>>>>>>>>>  ", 00, 00);
        cafeMenu[menuSize++] = MenuItem(1, "Burger", "Chicken Grilled Burger", 5.99, 20);
        cafeMenu[menuSize++] = MenuItem(2, "Pizza", "Fajita Pizza", 8.99, 15);
        cafeMenu[menuSize++] = MenuItem(3, "Hot Dog", "Classic Hot Dog", 3.49, 25);
        cafeMenu[menuSize++] = MenuItem(4, "French Fries", "Crispy French Fries", 2.99, 40);
        cafeMenu[menuSize++] = MenuItem(5, "Chicken Wings", "Spicy Chicken Wings", 7.99, 18);


        // Pakistani Food
        cafeMenu[menuSize++] = MenuItem(000, "", ">>>>>>>>>>>>>>>>>> PAKISTANI FOOD  >>>>>>>>>>>>>>>>>>  ", 00, 00);
        cafeMenu[menuSize++] = MenuItem(6, "Biryani", "Chicken Biryani", 10.99, 15);
        cafeMenu[menuSize++] = MenuItem(7, "Nihari", "Beef Nihari", 8.49, 12);
        cafeMenu[menuSize++] = MenuItem(8, "Seekh Kebab", "Spicy Seekh Kebab", 6.99, 20);
        cafeMenu[menuSize++] = MenuItem(9, "Haleem", "Traditional Haleem", 9.99, 10);



        // Sweets (Ice Creams)
        cafeMenu[menuSize++] = MenuItem(000, "", ">>>>>>>>>>>>>>>>>>  SWEETS (ICE CREAMS)   >>>>>>>>>>>>>>>>>>  ", 00, 00);
        cafeMenu[menuSize++] = MenuItem(10, "Chocolate Ice Cream", "Rich Chocolate Flavor", 3.99, 30);
        cafeMenu[menuSize++] = MenuItem(11, "Vanilla Ice Cream", "Classic Vanilla Flavor", 3.49, 25);
        cafeMenu[menuSize++] = MenuItem(12, "Strawberry Ice Cream", "Refreshing Strawberry Flavor", 4.49, 20);

        // Drinks
        cafeMenu[menuSize++] = MenuItem(000, "", ">>>>>>>>>>>>>>>>>>  DRINKS  >>>>>>>>>>>>>>>>>>  ", 00, 00);
        cafeMenu[menuSize++] = MenuItem(13, "Cola", "Classic Cola", 1.99, 40);
        cafeMenu[menuSize++] = MenuItem(14, "Lemonade", "Fresh Lemonade", 2.49, 35);
        cafeMenu[menuSize++] = MenuItem(15, "Iced Tea", "Sweetened Iced Tea", 2.99, 30);
        cafeMenu[menuSize++] = MenuItem(16, "Orange Juice", "Natural Orange Juice", 3.49, 25);



        // Save the updated menu to the file
        MenuItem::SaveMenu(cafeMenu, menuSize);

    }


    while (true)
    {
        cout << "1.REGISTER" << endl << "2.LOGIN" << endl << "3.LOGOUT" << endl << "4.MENU FOR YOUR TYPE" << endl << "5.EXIT" << endl << "ENTER YOUR CHOICE  " << endl;
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            userSystem.Register();
            break;
        case 2:
            userSystem.Login();
            break;
        case 3:
            userSystem.Logout();
            break;
        case 4:
            if (userSystem.GetUserType() == "customer")
            {
                userSystem.CustomerMenu(cafeMenu, menuSize);
            }
            else if (userSystem.GetUserType() == "staff")
            {
                userSystem.cafe_staff(cafeMenu, menuSize);
            }
            else if (userSystem.GetUserType() == "admin")
            {
                adminUser.ADMIN_MENU(cafeMenu, menuSize);
            }
            else
            {
                cout << "NOT LOGGED IN OR AN UNRECOGNIZED USER TYPE \n";
            }
            break;
            //case 6:
            //    // Save the menu to the file
            //    MenuItem::SaveMenu(cafeMenu, menuSize);
            //    break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << " ERROR ERROR ERROR !!!!!!!!!! \n";
        }
    }
    delete[] cafeMenu;
    return 0;
}
