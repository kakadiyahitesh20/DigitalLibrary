#include "../include/User.h"


void User::DisplayMenu()
{
    int choice=50;
    while(choice !=0 ) {
        cout << "-*-*-*-*-*-*-*-*-*-*-Welcome to Digital Library*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "1-Add user" << endl;
        cout << "2-Display user"<<endl;
        cout << "3-Modify user"<<endl;
        cout << "4-Delete user"<<endl;
        cin >> choice;
        switch (choice) {
            case 1:
                manageUser.adduser();
                break;
            case 2:
                manageUser.DisplayUsers();
                break;
            case 3:
                manageUser.modifyUser();
                break;
            case 4:
                manageUser.deleteUser();
                break;
            case 0:
                cout << "Exiting Loop****" << endl;
                choice = 0;

        }
    }
}
