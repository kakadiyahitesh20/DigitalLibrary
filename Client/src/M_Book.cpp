#include "../include/M_Book.h"
typedef boost::asio::ip::tcp asiotcp;

void M_Book::ipaddress(char *Copy) {
    Cptr_Book=Copy;
}

/* ------------------------------------------------
Display book information
Variables:
Return: book info, or an error if appropriate
------------------------------------------------------  */

void M_Book::DisplayBookdump(M_Book& output,int i) {

    ostream &os = cout;

    os << "******************************************" << std::endl;
    os << "\tS_NO: "<<output.s_no<<endl;
    os << "\tBookname: " << output.name<< endl;
    os << "\tAuthor :    " << output.author << endl;
    os << "\tPublisher:    " << output.publisher<<endl;
    os << "\tISBN:    " << output.ISBN<<endl;
    os << "\tCategory:    " << output.category<<endl;
    os << "******************************************" << std::endl;
}

/* ------------------------------------------------
Send bookinfor to server
Variables: passed info to send server
Return: book info, or an error if appropriate
------------------------------------------------------  */

string const M_Book::send2Server(string output) {

    boost::asio::io_service io_service;
    asiotcp::endpoint remote_endpoint = asiotcp::endpoint(boost::asio::ip::address_v4::from_string(Cptr_Book),13);
    asiotcp::socket socket(io_service);
    socket.open(asiotcp::v4());
    socket.connect(remote_endpoint);
    socket.send(boost::asio::buffer(output));

    array<char, 2048> recv_buf;
    size_t const received_bytes = socket.receive(boost::asio::buffer(recv_buf));
    string const inputmessage(recv_buf.data(), received_bytes);
    return inputmessage;
}

/* ------------------------------------------------
Add new book entry
------------------------------------------------------  */


void M_Book::addBook() {
    try {
        M_Book obj_book;
        stringstream ss;
        cout << "------------Add Book------------" << std::endl;
        cin.ignore();
        cout << "Enter Book name:" << std::endl;
        getline(cin, obj_book.name);
        cout << "Enter Author:" << std::endl;
        getline(cin, obj_book.author);
        cout << "Enter Publisher:" << std::endl;
        getline(cin, obj_book.publisher);
        cout << "Enter ISBN:" << endl;
        getline(cin, obj_book.ISBN);
        cout << "Enter Category:" << endl;
        getline(cin, obj_book.category);
        boost::archive::text_oarchive oa{ss};
        oa << obj_book;
        string output = "5|" + ss.str();
        string res=obj_book.send2Server(output);
        cout<<"Server->"<<"Bookname:"<<res<<endl;
    }
    catch (exception const &e)
    {
        cerr << e.what() <<endl;
    }
}


/* ------------------------------------------------
Remove book by s_no
Variables: Must passed s_no
------------------------------------------------------  */

void M_Book::deleteBook() {
    stringstream ss;
    M_Book delete_Book;
    cout << "------------Delete Book------------" << std::endl;
    cin.ignore();
    cout<<"Please enter Book s_no to delete:"<<endl;
    cin>>delete_Book.s_no;
    boost::archive::text_oarchive oa{ss};
    oa << delete_Book;
    string output = "8|" + ss.str();
    string res=delete_Book.send2Server(output);
    cout<<"Server->"<<res<<endl;
}

/* ------------------------------------------------
Modify book by s_no
Variables: Must passed s_no
------------------------------------------------------  */

void M_Book::modifyBook() {
    try {
        stringstream ss;
        M_Book modify_Book;
        cout << "------------Modify Book------------" << std::endl;
        cin.ignore();
        cout<<"Please enter S_no to modify:"<<endl;
        cin>>modify_Book.s_no;
        cin.ignore();
        cout << "Enter book Name:" << std::endl;
        getline(cin,modify_Book.name);
        cout << "Enter Book Author:" << std::endl;
        getline(cin,modify_Book.author);
        cout << "Enter Book ISBN:" << endl;
        getline(cin,modify_Book.ISBN);
        cout << "Enter Book Category:" << endl;
        getline(cin,modify_Book.category);
        boost::archive::text_oarchive oa{ss};
        oa << modify_Book;
        string output = "7|" + ss.str();
        string res=modify_Book.send2Server(output);
        cout<<"Server->"<<res<<endl;

    }
    catch (exception const &e)
    {
        cerr << e.what() << endl;
    }

}

/* ------------------------------------------------
For display book info extract data
------------------------------------------------------  */

void M_Book::DisplayBooks() {
    try {
        stringstream ss;
        M_Book DispBooks;
        boost::archive::text_oarchive oa{ss};
        oa << DispBooks;
        string output = "6|" + ss.str();
        string res=DispBooks.send2Server(output);
        std::stringstream ss1;
        ss1 << res;
        boost::archive::text_iarchive oa1{ss1};
        oa1 & BookData;

        for(int i=0;i<BookData.size();i++)
            DisplayBookdump(BookData[i],i);

    }
    catch (exception const &e)
    {
        cerr << e.what() << endl;
    }
}


/* ------------------------------------------------
Borrow book by username
Variables: Must passed username,book name
------------------------------------------------------  */

void M_Book::borrowedBook() {
    try {
        stringstream ss;
        string borrowUser;
        M_Book borrowBook;
        cout << "------------Borrow Book------------" << std::endl;
        cin.ignore();
        cout<<"Please enter Username:"<<endl;
        cin>>borrowUser;
        cin.ignore();
        cout << "Enter book Name:" << std::endl;
        getline(cin,borrowBook.name);
        boost::archive::text_oarchive oa{ss};
        oa << borrowBook;
        string output = "9|" + borrowUser+ "|" + ss.str();
        string res=borrowBook.send2Server(output);
        cout<<"Server->"<<res<<endl;

    }
    catch (exception const &e)
    {
        cerr << e.what() << endl;
    }
}

/* ------------------------------------------------
Display Borrow book extract info
------------------------------------------------------  */

void M_Book::DisplayBorrowed(){
    try {
        stringstream ss;
        M_Book DispBorrow;
        boost::archive::text_oarchive oa{ss};
        oa << DispBorrow;
        string output = "10|" + ss.str();
        string res=DispBorrow.send2Server(output);
        std::stringstream ss1;
        ss1 << res;
        boost::archive::text_iarchive oa1{ss1};
        oa1 & BookData;

        for(int i=0;i<BookData.size();i++)
            DisplayBookdump(BookData[i],i);

    }
    catch (exception const &e)
    {
        cerr << e.what() << endl;
    }
}

/* ------------------------------------------------
Return book by username
Variables: Must passed username,book name
------------------------------------------------------  */

void M_Book::returnBook() {
    try {
        stringstream ss;
        string returnUser;
        M_Book ReturnBook;
        cout << "------------Return Book------------" << std::endl;
        cin.ignore();
        cout<<"Please enter Username:"<<endl;
        cin>>returnUser;
        cin.ignore();
        cout << "Enter book Name:" << std::endl;
        getline(cin,ReturnBook.name);
        boost::archive::text_oarchive oa{ss};
        oa << ReturnBook;
        string output = "11|" + returnUser+ "|" + ss.str();
        string res=ReturnBook.send2Server(output);
        cout<<"Server->"<<res<<endl;

    }
    catch (exception const &e)
    {
        cerr << e.what() << endl;
    }
}

void M_Book::getbook(string res) {
    std::stringstream ss1;
    ss1 << res;
    boost::archive::text_iarchive oa1{ss1};
    oa1 & BookData;

    for(int i=0;i<BookData.size();i++)
        DisplayBookdump(BookData[i],i);
}
