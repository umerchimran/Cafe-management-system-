// Administrator.h
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"

using namespace std;
class Administrator : public User
{
public:
    Administrator();

    void LoadUserData();


    void ADMIN_MENU(MenuItem menu[], int& menuSize);

    void AddMenuItem(MenuItem menu[], int& menuSize);
    void RemoveMenuItem(MenuItem menu[], int& menuSize);

};

#endif // ADMINISTRATOR_H
