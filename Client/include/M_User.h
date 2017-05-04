#ifndef SERVER_M_USER_H
#define SERVER_M_USER_H
#include<vector>
#include <iostream>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio.hpp>
#include <fstream>
#include <sstream>
using namespace std;
static char *Cptr;
class M_User
{
public:
    void adduser();
    void deleteUser();
    void ipaddress(char*);
    string const send2Server(string);
    void DisplayUserdump(M_User&,int);
    void DisplayUsers();
    void modifyUser();
    friend class boost::serialization::access;

    template<typename Archive>

    void serialize(Archive &ar, const unsigned int version) {

        ar & name;
        ar & email;
        ar & phone;
        ar & uname;
    }

private:
    string name,uname,email,phone;

protected:
    vector<M_User> userData;
};


#endif
