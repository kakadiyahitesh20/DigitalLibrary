#include <iostream>
#include <boost/asio.hpp>
#include "include/User.h"
#include "include/M_User.h"
#include <memory>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstring>

//#include <boost/test/unit_test.hpp>



typedef boost::asio::ip::tcp asiotcp;
int main(int argc, char *argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: client <host>" << std::endl;
            return 1;
        }
        std::string message = "Hello server";
        boost::asio::io_service io_service;
        asiotcp::endpoint remote_endpoint = asiotcp::endpoint(boost::asio::ip::address_v4::from_string(argv[1]), 13);
        asiotcp::socket socket(io_service);
        socket.open(asiotcp::v4());
        socket.connect(remote_endpoint);
        socket.send(boost::asio::buffer(message));
        User obj_User;
        M_User IP_user;
        M_Book IP_Book;
        IP_user.ipaddress(argv[1]);
        IP_Book.ipaddress(argv[1]);
        obj_User.DisplayMenu();

    }
        catch (std::exception const &e)
        {
            std::cerr << e.what() << std::endl;
        }
    return 0;
}


