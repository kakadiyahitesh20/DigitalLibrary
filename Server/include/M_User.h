#ifndef SERVER_M_USER_H
#define SERVER_M_USER_H
#include<iostream>
#include<vector>
#include <fstream>
#include <sstream>
#include<boost/asio.hpp>
#include<string>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
using namespace std;

/* ------------------------------------------------
For user class method operation at server side
------------------------------------------------------  */

class M_User
{
public:
    string addUser(string);
    string getUsersList();
    void DisplayUserDump(M_User const,int);
    string ModifyUser(string);
    string deleteUser(string);
    bool addBorrowedBook(string,int);
    bool removeBorrowedBook(string,int);
    vector<int> borrowedUser(string);
    friend class boost::serialization::access;

    template<typename Archive>

    void serialize(Archive &ar, const unsigned int version) {

        ar & name;
        ar & email;
        ar & phone;
        ar & uname;
        ar & booksBorrowed;
    }

private:
    string name,email,phone,uname;
    vector<int> booksBorrowed;
protected:
    vector<M_User> userData;
};

#endif
