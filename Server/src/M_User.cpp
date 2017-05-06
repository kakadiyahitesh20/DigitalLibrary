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
string M_User::ModifyUser(string inputM) {
    M_User modobj;
    std::stringstream ss;
    ss << inputM;
    boost::archive::text_iarchive ia{ss};
    ia >> modobj;
    for(int i=0;i<userData.size();i++){
        if(modobj.uname == userData[i].uname)
        {
            userData.erase(userData.begin()+i);
            userData.push_back(modobj);
            return modobj.uname +" Successfully modified";
        }
    }
    return modobj.uname + "User not found";
}
string M_User::deleteUser(string inputM) {
    M_User delobj;
    std::stringstream ss;4
    ss << inputM;
    boost::archive::text_iarchive ia{ss};
    ia >> delobj;
    cout<<delobj.uname<<endl;
    for(int i=0;i<userData.size();i++) {
        if (delobj.uname == userData[i].uname) {
            userData.erase(userData.begin() + i);
            return delobj.uname + " Successfully deleted";
        }
    }
    return delobj.uname + "User not found";
}







