//
// Created by Bhargav on 2023-03-01.
//

#ifndef SQA_PROJECT_USER_H
#define SQA_PROJECT_USER_H
#include <string>
using namespace std;

class User {
private:
private:
    string userName;
    string userType;
    float userCredit;
    bool isLoggedIn;
public:
    User();

    User(string name, string type, float credit);

    string getUserName();
    string getUserType();
    float getUserCredit();
    bool getIsLoggedIn();

    void setUserName(string name);
    void setUserType(string type);
    void setUserCredit(float credit);
    void setIsLoggedIn(bool loggedIn);

    // void logIn();

    // void logOut();

    string checkUser(string user_name, string user_file);
    int checkCredit(string user_name, string user_file);
    int locateUserLine(string name, string user_file);

    int savetoFile (string usr, int toAddCredit, string user_file, string transactionFile );
};

#endif //SQA_PROJECT_USER_H
