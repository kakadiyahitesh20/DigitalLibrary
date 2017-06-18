#include "../include/M_User.h"
typedef boost::asio::ip::tcp asiotcp;

void M_User::ipaddress(char *Copy) {
        Cptr=Copy;
}

/* ------------------------------------------------
Display user info
------------------------------------------------------  */

void M_User::DisplayUserdump(M_User& output,int i) {

        ostream &os = cout;
        os << "User:"<<++i<<endl;
        os << "******************************************" << std::endl;
        os << "\tUsername: " << output.uname<< endl;
        os << "\tName :    " << output.name << endl;
        os << "\tEmail:    " << output.email<<endl;
        os << "\tPhone:    " << output.phone<<endl;
        os << "******************************************" << std::endl;
}

/* ------------------------------------------------
Send user data to server
------------------------------------------------------  */

string const M_User::send2Server(string output) {

        boost::asio::io_service io_service;
        asiotcp::endpoint remote_endpoint = asiotcp::endpoint(boost::asio::ip::address_v4::from_string(Cptr),13);
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
Add new user
------------------------------------------------------  */

void M_User::adduser() {
        try {
                M_User obj;
                stringstream ss;
                cout << "------------Add User------------" << std::endl;
                cin.ignore();
                cout << "Enter First Name:" << std::endl;
                getline(cin, obj.name);
                cout << "Enter User Email:" << std::endl;
                getline(cin, obj.email);
                cout << "Enter User name:" << std::endl;
                getline(cin, obj.uname);
                cout << "Enter Phone Number:" << endl;
                getline(cin, obj.phone);
                boost::archive::text_oarchive oa{ss};
                oa << obj;
                string output = "1|" + ss.str();
                string res=obj.send2Server(output);
                cout<<"Server->"<<"Username:"<<res<<endl;
        }
        catch (exception const &e)
        {
                cerr << e.what() <<endl;
        }
}

/* ------------------------------------------------
Remove user by username
Variables: Must passed username
------------------------------------------------------  */

void M_User::deleteUser() {
    stringstream ss;
    M_User delete_User;
    cout << "------------Delete User------------" << std::endl;
    cin.ignore();
    cout<<"Please enter username to delete:"<<endl;
    getline(cin,delete_User.uname);
    boost::archive::text_oarchive oa{ss};
    oa << delete_User;
    string output = "4|" + ss.str();
    string res=delete_User.send2Server(output);
    cout<<"Server->"<<res<<endl;
}

/* ------------------------------------------------
Modify user by username
Variables: Must passed username and other info
------------------------------------------------------  */

void M_User::modifyUser() {
        try {
                stringstream ss;
                M_User modify_User;
                cout << "------------Modify User------------" << std::endl;
                cin.ignore();
                cout<<"Please enter username to modify:"<<endl;
                getline(cin,modify_User.uname);
                cout << "Enter First Name:" << std::endl;
                getline(cin,modify_User.name);
                cout << "Enter User Email:" << std::endl;
                getline(cin,modify_User.email);
                cout << "Enter Phone Number:" << endl;
                getline(cin,modify_User.phone);
                boost::archive::text_oarchive oa{ss};
                oa << modify_User;
                string output = "3|" + ss.str();
                string res=modify_User.send2Server(output);
                cout<<"Server->"<<res<<endl;

        }
        catch (exception const &e)
        {
                cerr << e.what() << endl;
        }

}

/* ------------------------------------------------
Display user extract info
------------------------------------------------------  */

void M_User::DisplayUsers() {
        try {
                stringstream ss;
                M_User DispUsers;
                boost::archive::text_oarchive oa{ss};
                oa << DispUsers;
                string output = "2|" + ss.str();
                string res=DispUsers.send2Server(output);
                std::stringstream ss1;
                ss1 << res;
                boost::archive::text_iarchive oa1{ss1};
                oa1 & userData;

                for(int i=0;i<userData.size();i++)
                        DisplayUserdump(userData[i],i);

        }
        catch (exception const &e)
        {
                cerr << e.what() << endl;
        }
}

/* ------------------------------------------------
Display borrow book by username
Variable : Must passed username
------------------------------------------------------  */

string M_User::UsersBorrowed()  {
        try {
                stringstream ss;
                M_User barrowedUsers;
                string user;
                cout << "------------User Borrowed books------------" << std::endl;
                cin.ignore();
                cout<<"Please enter username:"<<endl;
                cin>>user;
                boost::archive::text_oarchive oa{ss};
                oa << barrowedUsers;
                string output = "12|"+ user + "|" + ss.str();
                string res=barrowedUsers.send2Server(output);
                return res;
                /*std::stringstream ss1;
                ss1 << res;
                boost::archive::text_iarchive oa1{ss1};
                oa1 & userData;

                for(int i=0;i<userData.size();i++)
                        cout<<"Book Serial number:"<<userData[i].name;
                        */
        }
        catch (exception const &e)
        {
                cerr << e.what() << endl;
        }
}

