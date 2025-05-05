#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
using namespace std;
class Customer : public User
{
public:

	Customer();

	void CustomerMenu(MenuItem menu[], int& menuSize);


};















#endif