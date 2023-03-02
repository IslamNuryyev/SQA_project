#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class User {
private:
    string userName;
    string userType;
    float userCredit;
    bool isLoggedIn;
public:
    User() : userName(""), userType(""), userCredit(0.0) {}
    
    User(string name, string type, float credit) {
        this->userName = name;
        this->userType = type;
        this->userCredit = credit;
    }

    string getUserName() {
        return userName;
    }
    string getUserType() { 
        return userType; 
    }
    float getUserCredit() { 
        return userCredit; 
    }
    bool getIsLoggedIn() {
        return isLoggedIn;
    }

    void setUserName(string name) { 
        if (name.length() > 15) {
        userName = name.substr(0, 15);
        } else {
        userName = name;
        }
    }

    void setUserType(string type) { 
        userType = type; 
    }

    void setUserCredit(float credit) { 
        if (credit > 999999) {
            userCredit = 999999; 
        } else {
            userCredit = credit;
        } 
    }
    void setIsLoggedIn(bool loggedIn) {
        isLoggedIn = loggedIn;
    }

    void logIn() {
    }

    void logOut() {
    }
};
