#include <iostream>
#include <fstream>
#include <string>
#include "Admin.h"

class Create {
    // member variables that will be used to create a user object
    private:
        string username;
        string usertype;
        float userCredit;

        // user object stored here after creation
        User user;


    public:
    // constructors for Create class
    Create() : username(""), usertype(""), userCredit(0.0) {}

    Create(string name, string type, float credit) {
        this->username = name;
        this->usertype = type;
        this->userCredit = credit;
    }


        
    // ASKS CURRENT USER TO INPUT USERNAME, USERTYPE, USERCREDITS
    // CREATES NEW USER OBJECT AND ASSIGNS IT TO MEMBER VARIABLE user
    void createUser() {
        cout << "Enter username: ";
        cin >> username;

        cout << "Enter user type: ";
        cin >> usertype;

        cout << "Enter user credit: ";
        cin >> userCredit;

        User newUser(username, usertype, userCredit);
        user = newUser;
    }

    // ACCESSES MEMBER VARIABLE user AND ADDS THE USER TO THE user_account.txt FILE
    void saveToFile() {
        ofstream userFile("user_account.txt", ios::app);
        if (userFile.is_open()) 
        {
            userFile <<  user.getUserName() << "_" << user.getUserType() << "_" << user.getUserCredit() << endl;
            userFile.close();
            cout << "Added " << user.getUserName() << "_" << user.getUserType() << "_" << user.getUserCredit() <<
            " to user_account.txt" << endl;
        } else {
            cout << "Error: could not open user_account.txt for writing." << endl;
        }
    }

    void isAdmin() {
        // TODO : currently need a way to allow an admin to access this classes variables
    }
};