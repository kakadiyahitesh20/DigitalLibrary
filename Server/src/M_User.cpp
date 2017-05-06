#include "../include/M_User.h"

string M_User::addUser(string inputM) {
    M_User obj;
    std::stringstream ss;
    ss << inputM;
    boost::archive::text_iarchive ia{ss};
    ia >> obj;
    userData.push_back(obj);
    cout << "User Name:" << obj.uname << " added"<<endl;
    cout<<"testing::"<<userData[0].uname;
    for (int i = 0; i < userData.size(); i++) {
        DisplayUserDump(userData[i],i);
    }
    return obj.uname +" Successfully added";

}

void M_User :: DisplayUserDump(M_User const userObj, int i)
{
    std::ostream &os = std::cout;
    os <<"----------------------------------------------"<<std::endl;
    os << ++i << " User " << std::endl;
    os << "Name : " << userObj.name<< std::endl;
    os << "User Name : " << userObj.uname << std::endl;
    os << "Email : " << userObj.email << std::endl;
    os << "Phone : " << userObj.phone << std::endl;
    os <<"----------------------------------------------"<<std::endl;
}
string M_User::getUsersList(){

    try {
        std::stringstream ss;
        boost::archive::text_oarchive oa{ss};
        oa & userData;
        std::string output = ss.str();
        return output;
    }catch (std :: exception& e){
        std::cerr << e.what()<< std::endl;
    }
}

