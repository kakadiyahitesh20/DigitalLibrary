#include <iostream>
#include <array>
#include<vector>
#include"include/M_User.h"
#include"include/M_Book.h"
#include<boost/asio.hpp>
#include<string>
#include <boost/serialization/vector.hpp>
#include<boost/algorithm/string.hpp>
using namespace std;

int main() {
    bool loop=true;
    try
    {
        typedef boost::asio::ip::tcp asiotcp;
        boost::asio::io_service io_service;
        M_User userObj;
        M_Book bookObj;
        while(true) {
            asiotcp ::socket socket(io_service);
            asiotcp::acceptor a(io_service, asiotcp::endpoint(asiotcp::v4(), 13));
            a.accept(socket);
            array<char, 2048> recv_buf;
            size_t const received_bytes = socket.receive(boost::asio::buffer(recv_buf));
            string const inputmessage(recv_buf.data(), received_bytes);
            cout << "Client sent message: \"" << inputmessage << "\"" << endl;
            vector<string> inputM;
            boost::split(inputM,inputmessage,boost::is_any_of("|"));
            int choice;
            istringstream (inputM[0]) >> choice;
            switch(choice) {
                case 1 : {
                    string res = userObj.addUser(inputM[1]);
                    socket.send(boost::asio::buffer(res));
                    break;
                }
                case 2 : {
                    string AllUsers = userObj.getUsersList();
                    socket.send(boost::asio::buffer(AllUsers));
                    break;
                }
                case 3: {
                    string modifyUser = userObj.ModifyUser(inputM[1]);
                    socket.send(boost::asio::buffer(modifyUser));
                    break;
                }
                case 4:{
                    string delete_user=userObj.deleteUser(inputM[1]);
                    socket.send(boost::asio::buffer(delete_user));
                    break;

                }
                case 5 : {
                    string res = bookObj.addBook(inputM[1]);
                    socket.send(boost::asio::buffer(res));
                    break;
                }
                case 6 : {
                    string allBooks = bookObj.getBookList();
                    socket.send(boost::asio::buffer(allBooks));
                    break;
                }
                case 7: {
                    string modifyBook = bookObj.ModifyBook(inputM[1]);
                    socket.send(boost::asio::buffer(modifyBook));
                    break;
                }
                case 8:{
                    string delete_book=bookObj.deleteBook(inputM[1]);
                    socket.send(boost::asio::buffer(delete_book));
                    break;

                }
                case 9:{

                    int borrowed_book=bookObj.borrowedBook(inputM[2]);
                    string output;
                    if(borrowed_book!=0) {
                        bool flag = userObj.addBorrowedBook(inputM[1], borrowed_book);
                        if(flag)
                            output="Borrowed successful";
                        else
                            output="username is not found";

                    }else{
                        output="Book name is invalid or already borrowed";
                    }
                    socket.send(boost::asio::buffer(output));
                    break;
                }
                case 10:{
                    string borrowedBook = bookObj.getBorrowedList();
                    socket.send(boost::asio::buffer(borrowedBook));
                    break;
                }
                case 11:{
                    int return_book=bookObj.returnBook(inputM[2]);
                    string output;
                    if(return_book!=0) {
                        bool flag = userObj.removeBorrowedBook(inputM[1], return_book);
                        if(flag)
                            output="Returned successful";
                        else
                            output="username is not found";

                    }else{
                        output="Book name is invalid or no book to return";
                    }
                    socket.send(boost::asio::buffer(output));
                    break;
                }
                case 12:{
                    vector<int> AllUsersbook = userObj.borrowedUser(inputM[1]);
                    string bookList=bookObj.getbook(AllUsersbook);
                    socket.send(boost::asio::buffer(bookList));
                    break;

                }
            }
        }
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

