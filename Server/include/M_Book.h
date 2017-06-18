#ifndef SERVER_M_BOOKS_H
#define SERVER_M_BOOKS_H
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
#include"../include/M_User.h"

using namespace std;

/* ------------------------------------------------
For book class method operation at server side
------------------------------------------------------  */

class M_Book
{
public:
    string addBook(string);
    string getBookList();
    void DisplayBookDump(M_Book const,int);
    string ModifyBook(string);
    string deleteBook(string);


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

    int borrowedBook(string);
    string getBorrowedList();
    int returnBook(string);
    string getbook(vector<int>);

private:
    int s_no = 0;
    bool borrowed=false;
    string name,author,publisher,ISBN,category ;
protected:
    vector<M_Book> bookData;
};

#endif
