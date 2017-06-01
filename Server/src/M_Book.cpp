#include "../include/M_Book.h"


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

