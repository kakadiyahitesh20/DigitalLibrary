#include "../include/M_Book.h"

/* ------------------------------------------------
Add new book entry server side
Return : msg
------------------------------------------------------  */


string M_Book::addBook(string inputM) {
    M_Book obj_Book;
    std::stringstream ss;
    ss << inputM;
    boost::archive::text_iarchive ia{ss};
    ia >> obj_Book;
    obj_Book.s_no = bookData.size() + 1;
    obj_Book.borrowed = false;
    bookData.push_back(obj_Book);
    cout << "BookName:" << obj_Book.name << " added"<<endl;
    for (int i = 0; i < bookData.size(); i++) {
        DisplayBookDump(bookData[i],i);
    }
    return obj_Book.name +" Successfully added";

}

/* ------------------------------------------------
Display book server side
------------------------------------------------------  */

void M_Book :: DisplayBookDump(M_Book const bookObj, int i)
{
    ostream &os = cout;
    os << "Book no"<<++i<<endl;
    os << "******************************************" << std::endl;
    os << "\tS_no: " << bookObj.s_no<< endl;
    os << "\tBookname: " << bookObj.name<< endl;
    os << "\tAuthor :    " << bookObj.author << endl;
    os << "\tPublisher:    " << bookObj.publisher<<endl;
    os << "\tISBN:    " << bookObj.ISBN<<endl;
    os << "\tCategory:    " << bookObj.category<<endl;
    os << "******************************************" << std::endl;
}

/* ------------------------------------------------
Display book list extract list info
------------------------------------------------------  */

string M_Book::getBookList(){

    try {
        std::stringstream ss;
        boost::archive::text_oarchive oa{ss};
        oa & bookData;
        std::string output = ss.str();
        return output;
    }catch (std :: exception& e){
        std::cerr << e.what()<< std::endl;
    }
}
string M_Book::ModifyBook(string inputM) {
    M_Book modobj;
    std::stringstream ss;
    ss << inputM;
    boost::archive::text_iarchive ia{ss};
    ia >> modobj;
    for(int i=0;i<bookData.size();i++){
        if(modobj.s_no == bookData[i].s_no)
        {
            bookData.erase(bookData.begin()+i);
            bookData.push_back(modobj);
            return modobj.name +" Successfully modified";
        }
    }
    return modobj.s_no + "Book not found";
}

/* ------------------------------------------------
Modify book entry server side
Return : msg
------------------------------------------------------  */

string M_Book::deleteBook(string inputM) {
    M_Book delobj;
    std::stringstream ss;
    ss << inputM;
    boost::archive::text_iarchive ia{ss};
    ia >> delobj;
    cout<<delobj.s_no<<endl;
    for(int i=0;i<bookData.size();i++) {
        if (delobj.s_no == bookData[i].s_no) {
            bookData.erase(bookData.begin() + i);
            return delobj.name + " Successfully deleted";
        }
    }
    return delobj.s_no + "Book not found";
}

/* ------------------------------------------------
Borrow book extract info at server side
------------------------------------------------------  */

int M_Book::borrowedBook(string inputM) {
    try {
        //M_User userObj;
        M_Book borrowObj;
        std::stringstream ss;
        ss << inputM;
        boost::archive::text_iarchive ia{ss};
        ia >> borrowObj;
        for(int i=0;i<bookData.size();i++){
            if(borrowObj.name == bookData[i].name) {
                if(!bookData[i].borrowed) {
                    bookData[i].borrowed = true;
                    return bookData[i].s_no;
                }
            }
        }
        return 0;
    }catch (std :: exception& e){
        std::cerr << e.what()<< std::endl;
    }
}

/* ------------------------------------------------
Borrow book list extract info at server side
------------------------------------------------------  */

string M_Book::getBorrowedList(){

    try {
        vector<M_Book> borrowed;
        std::stringstream ss;
        boost::archive::text_oarchive oa{ss};
        for(int i=0;i<bookData.size();i++){
            if(bookData[i].borrowed == true)
            {
                borrowed.push_back(bookData[i]);
            }
        }
        for (int i = 0; i < borrowed.size(); i++) {
            DisplayBookDump(borrowed[i],i);
        }
        oa & borrowed;

        std::string output = ss.str();
        return output;
    }catch (std :: exception& e){
        std::cerr << e.what()<< std::endl;
    }
}

/* ------------------------------------------------
Return book extract info at server side
------------------------------------------------------  */

int M_Book::returnBook(string inputM) {
    try {
        //M_User userObj;
        M_Book returnObj;
        std::stringstream ss;
        ss << inputM;
        boost::archive::text_iarchive ia{ss};
        ia >> returnObj;
        for(int i=0;i<bookData.size();i++){
            if(returnObj.name == bookData[i].name) {
                if(bookData[i].borrowed == true) {
                    bookData[i].borrowed = false;
                    return bookData[i].s_no;
                }
            }
        }
        return 0;
    }catch (std :: exception& e){
        std::cerr << e.what()<< std::endl;
    }
}

/* ------------------------------------------------
Get book extract info at server side
------------------------------------------------------  */

string M_Book::getbook(vector<int> booksNo)
{
    vector<M_Book> dump;
    std::stringstream ss;
    boost::archive::text_oarchive oa{ss};
    for(int i=0;i<booksNo.size();i++) {
        for (int j = 0; j < bookData.size(); j++){
            if (booksNo[i] == bookData[j].s_no) {
                if (bookData[j].borrowed == true) {
                    dump.push_back(bookData[j]);
                }
            }
        }
    }
    for (int i = 0; i < dump.size(); i++) {
        DisplayBookDump(dump[i],i);
    }
    oa & dump;

    std::string output = ss.str();
    return output;
}
