#ifndef CLIENT_USER_H
#define CLIENT_USER_H
#include<iostream>
#include<string>
#include"../include/M_User.h"
#include"../include/M_Book.h"
using namespace std;

class User
{
public:
    void DisplayMenu();
private:
    M_User manageUser;
    M_Book manageBook;
};

#endif
