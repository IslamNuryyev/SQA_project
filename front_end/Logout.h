#include <iostream>
#include <fstream>
#include <string>
#include "User.h"

class Logout {
private:
    User user;

public:
    Logout() : user() {};
    Logout(const User& newUser) : user(newUser) {};

    User getUserName() const { return user; }
    void setUserName(const User& newUser) { user = newUser; }

    void writeDailyTrans() {
    }

    bool isLoggedIn() {
        return user.getIsLoggedIn();
    }

    void logOut() {
        user.setIsLoggedIn(false);
        exit(0);
    }
};