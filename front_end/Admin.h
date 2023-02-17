#include <iostream>
#include <string>
#include <fstream>
#include "User.h"

using namespace std;

class Admin : public User {
// private:
//     bool isAdminLoggedIn;

public:
    // Admin() : isAdminLoggedIn(false) {}

    // bool getIsAdminLoggedIn() {
    //     return isAdminLoggedIn;
    // }

    // void setIsAdminLoggedIn(bool loggedIn) {
    //     isAdminLoggedIn = loggedIn;
    // }

    void createUser(string name, string type, float credit) {
        // code to create a new user with the given name, type, and credit
        User newUser(name, type, credit);

        // save new user to user_account.txt
        ofstream userFile("user_account.txt", ios::app);
        if (userFile.is_open()) 
        {
            userFile <<  newUser.getUserName() << "_" << newUser.getUserType() << "_" << newUser.getUserCredit() << endl;
            userFile.close();
            cout << "Added " << newUser.getUserName() << "_" << newUser.getUserType() << "_" << newUser.getUserCredit() <<
            " to user_account.txt" << endl;
        } else {
            cout << "Error: could not open user_account.txt for writing." << endl;
        }
        
    }

    void deleteUser(string name) {
        // code to delete the user with the given name
    }

    void addCredit(string name, float credit) {
        // code to add the given credit to the user with the given name
    }
};


