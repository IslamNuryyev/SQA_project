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
    static vector<string> userNames; // to store all user names
    static bool isUserNameTaken(const string& name) {}
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

    int savetoFile (string usr, long total_credit, int currentCredit, string user_file, string transactionFile  );
};

// int main() {
//     User user1("Islam", "ST", 1000.0);
//     cout << user1.getUserName() << endl;
// }
#endif //SQA_PROJECT_USER_H
