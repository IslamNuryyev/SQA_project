#include <iostream>
#include <fstream>
#include <string>
#include "User.h"

class Login {
private:
    User user;

public:
    Login() : user() {}
    Login(const User& newUser) : user(newUser) {}

    User getUserName() const { return user; }
    void setUserName(const User& newUser) { user = newUser; }

    void readUserFile() {
        ifstream file("user_account.txt");
        string line;

        while (getline(file, line))
        {   
            cout << "user = " << line << endl;
        }

        file.close();
    }

    void showAvailableItems() {
        ifstream file2("tickets.txt");
        string line;

        while (getline(file2, line))
        {   
            cout << "-- Here are the available items --" << endl;
            cout << "item = " << line << endl;
        }
        file2.close();
    }
};