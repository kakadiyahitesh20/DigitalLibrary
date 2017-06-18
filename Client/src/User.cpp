#include "../include/User.h"

/* ------------------------------------------------
Display Menu of user operation
------------------------------------------------------  */

void User::DisplayMenu()
{
    int choice=50;
    while(choice !=0 ) {
        cout << "-*-*-*-*-*-*-*-*-*-*-Welcome to Digital Library*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "1-Add user" << endl;
        cout << "2-Display user"<<endl;
        cout << "3-Modify user"<<endl;
        cout << "4-Delete user"<<endl;
        cout << "5-Add book"<<endl;
        cout << "6-Display Book"<<endl;
        cout << "7-Modify Book"<<endl;
        cout << "8-Delete Book"<<endl;
        cout << "9-Borrow Book"<<endl;
        cout << "10-Display All Borrowed Book"<<endl;
        cout << "11-Return Book"<<endl;
        cout << "12-Diplay Users borrowed book"<<endl;

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
            case 5:
                manageBook.addBook();
                break;
            case 6:
                manageBook.DisplayBooks();
                break;
            case 7:
                manageBook.modifyBook();
                break;
            case 8:
                manageBook.deleteBook();
                break;
            case 9:
                manageBook.borrowedBook();
                break;
            case 10:
                manageBook.DisplayBorrowed();
                break;
            case 11:
                manageBook.returnBook();
                break;
            case 12: {
                string booklist = manageUser.UsersBorrowed();
                manageBook.getbook(booklist);
                break;
            }
            case 0:
                cout << "Exiting Loop****" << endl;
                choice = 0;

        }
    }
}
