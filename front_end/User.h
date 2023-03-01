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
        userName = name; 
    }
    void setUserType(string type) { 
        userType = type; 
    }
    void setUserCredit(float credit) { 
        userCredit = credit; 
    }
    void setIsLoggedIn(bool loggedIn) {
        isLoggedIn = loggedIn;
    }

    void logIn() {
    }

    void logOut() {
    }

//     void createAccount() {
//         ofstream outfile("user_account.txt", ios::out | ios::app);
//         string newUserName;
//         string newUserType;
//         int newUserCredit;

//         cout << "Enter new user username: ";
//         cin >> userName;
//         cout << "Enter new user user type: ";
//         cin >> userType;
//         cout << "Enter new user initial credit: ";
//         cin >> userCredit;
//         outfile <<userName<<"_"<<userType<<"_"<<userCredit  << std::endl;
    
//         outfile.close();
    
// }
};

// int main() {
//     User user1("Islam", "ST", 1000.0);
//     cout << user1.getUserName() << endl;
// }
