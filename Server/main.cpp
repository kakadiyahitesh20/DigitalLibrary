#include <iostream>
#include <array>
#include<vector>
#include"include/M_User.h"
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
                    string modify = userObj.ModifyUser(inputM[1]);
                    socket.send(boost::asio::buffer(modify));
                    break;
                }
                case 4:{
                    string delete_user=userObj.deleteUser(inputM[1]);
                    socket.send(boost::asio::buffer(delete_user));
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

