#ifndef CLIENT_USER_H
#define CLIENT_USER_H
#include<iostream>
#include<string>

#include"M_User.h"

using namespace std;

class User
{
public:
    void DisplayMenu();
private:
    M_User manageUser;
};

#endif
