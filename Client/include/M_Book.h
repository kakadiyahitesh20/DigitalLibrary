#ifndef SERVER_M_Book_H
#define SERVER_M_Book_H
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
#include"../include/M_User.h"


using namespace std;
static char *Cptr_Book;
class  M_Book
{
public:
    void addBook();
    void deleteBook();
    void ipaddress(char*);
    string const send2Server(string);
    void DisplayBookdump(M_Book&,int);
    void DisplayBooks();
    void modifyBook();
    void borrowedBook();
    void DisplayBorrowed();
    void returnBook();
    void getbook(string);
    friend class boost::serialization::access;

    template<typename Archive>

    void serialize(Archive &ar, const unsigned int version) {

        ar & name;
        ar & author;
        ar & publisher;
        ar & ISBN;
        ar & category;
        ar & s_no;
        ar & borrowed;
    }

private:
    int s_no;
    bool borrowed=false;
    string name,author,publisher,ISBN,category;

protected:
    vector<M_Book> BookData;
};


#endif
