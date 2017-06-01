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
    std::stringstream ss;
    ss << inputM;
    boost::archive::text_iarchive ia{ss};
    ia >> delobj;
    for(int i=0;i<userData.size();i++) {
        if (delobj.uname == userData[i].uname) {
            userData.erase(userData.begin() + i);
            return delobj.uname + " Successfully deleted";
        }
    }
    return delobj.uname + "User not found";
}

bool M_User::addBorrowedBook(string uname,int book_SN){

    try {
        cout<<userData.size();
        cout<<uname;
        for(int i=0;i<userData.size();i++){
            if(userData[i].uname == uname)
            {
                userData[i].booksBorrowed.push_back(book_SN);
                return true;
            }
        }
        return false;

    }catch (std :: exception& e){
        std::cerr << e.what()<< std::endl;
    }
}

bool M_User::removeBorrowedBook(string uname,int book_SN){

    try {
        cout<<userData.size();
        for(int i=0;i<userData.size();i++){
            if(userData[i].uname == uname) {
                vector<int> tmp =  userData[i].booksBorrowed;
                for (int j = 0; j < tmp.size(); j++) {
                    if (tmp[j] == book_SN) {
                        userData[i].booksBorrowed.erase(userData[i].booksBorrowed.begin() + j);
                        return true;
                    }
                }
            }

        }
        return false;

    }catch (std :: exception& e){
        std::cerr << e.what()<< std::endl;
    }
}

vector<int> M_User::borrowedUser(string inputM) {
    M_User borrowobj;
    vector<M_User> Dump;
    for(int i=0;i<userData.size();i++) {
        if (userData[i].uname == inputM) {
           return userData[i].booksBorrowed;
        }
    }
}
