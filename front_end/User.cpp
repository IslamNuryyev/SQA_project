//
// Created by Bhargav on 2023-03-01.
//

#include "User.h"

#include <iostream>
#include <string>
#include <fstream>
#include "User.h"

using namespace std;
User::User() : userName(""), userType(""), userCredit(0.0) {}

User::User(string name, string type, float credit) {
        this->userName = name;
        this->userType = type;
        this->userCredit = credit;
    }

    string User::getUserName() {
        return userName;
    }
    string User::getUserType() {
        return userType;
    }
    float User::getUserCredit() {
        return userCredit;
    }
    bool User::getIsLoggedIn() {
        return isLoggedIn;
    }

    void User::setUserName(string name) {
        if (isUserNameTaken(name)) {
            throw runtime_error("User name already taken.");
        }

        // removes the old user name and add the new one to the list
        auto it = find(userNames.begin(), userNames.end(), name);
        if (it != userNames.end()) {
            userNames.erase(it);
        }

        if (name.length() > 15) {
        userName = name.substr(0, 15);
        userNames.push_back(name.substr(0, 15));
        } else {
        userName = name.substr(0, 15);
        }
    }
    void User::setUserType(string type) {
        userType = type;
    }
    void User::setUserCredit(float credit) {
        if (credit > 999999) {
            userCredit = 999999; 
        } else {
            userCredit = credit;
        } 
    }
    void User::setIsLoggedIn(bool loggedIn) {
        isLoggedIn = loggedIn;
    }

    static vector<string> userNames; // to store all user names

    static bool isUserNameTaken(const string& name) {
        // check if the given user name is already taken
        if (name.length() > 15) {
        return find(userNames.begin(), userNames.end(), name.substr(0, 15)) != userNames.end();
        } else {
            return find(userNames.begin(), userNames.end(), name) != userNames.end();
        }
    }
    

    // void logIn() {
    // }

    // void logOut() {
    // }

    string User::checkUser(string user_name, string user_file) {
        ifstream file(user_file);
        string line;
        string type = "";
        char delimiter = '_';

        while (getline(file, line)) {
            string usr_name = line.substr(0, line.find(delimiter));
            string usr_type = line.substr(line.find(delimiter)+1, 2);

            if (user_name ==  usr_name) {
                if (usr_type == "FS" ) {
                    type= "FS";
                    break;
                }
                else if (usr_type == "BS" ) {
                    type= "BS";
                    break;
                }
                else if (usr_type == "SS" ) {
                    type = "SS";
                    break;
                }
                else if (usr_type == "AA" ) {
                    type = "AA";
                    break;
                }
            }
        }

        file.close();
        return type;
    }
    
    int User::checkCredit(string user_name, string user_file) {
        ifstream file3(user_file);

        string line;
        bool flag = false;
        string exist = "";
        char delimiter = '_';
        int credit_amount = 0;

        while (getline(file3, line)) {
            string usr_name = line.substr(0, line.find(delimiter));
            string usr_type = line.substr(line.find(delimiter)+1, 2);
            string amount_on_file = line.substr(line.find(delimiter)+4, 8);

            // cout<< "Hello there: " << credit_amount << endl;
            // exist = "Hello there: ";

            if (user_name ==  usr_name) {
                credit_amount = stoi(amount_on_file);

            }
        }
        file3.close();
        return credit_amount;

    }
    int User::locateUserLine(string name, string user_file) {  // locating line to be deleted of a user
        ifstream in_File5(user_file);
        if (!in_File5.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return -1;
        }
        int lineNumber = 1;
        char delimiter = '_';
        int lineToReplace;
        string line;
        if (!in_File5.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return -1;
        }

        while (getline(in_File5, line)) {
            string usr_name = line.substr(0, line.find(delimiter));
            //string usr_type = line.substr(line.find(delimiter)+1, 2);

            if (line.find(name) != string::npos) {
                // inFile.close();

                lineToReplace = lineNumber;
                //tempFile << line << endl;
                // cout << "Username located at: " << lineNumber << endl;
                return lineNumber;

            }
            lineNumber++;
        }
        in_File5.close();
        return -1;
    }

    int User::savetoFile (string usr, long total_credit, int currentCredit, string user_file, string transactionFile  ) {
        ofstream Create_Trans2(transactionFile,ios::out | ios::app);
        ifstream inFile6(user_file);
        ofstream temp_File3("temp4.txt");
        string newValue; // this will contain new line with subtracted amount

        if (!inFile6.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return -1;
        }

        newValue = usr + "_" + checkUser(usr,user_file) + "_" +  to_string(total_credit);

        int lineNumber = 1;
        int lineToReplace = locateUserLine(usr, user_file);
        string line;

        if (lineToReplace > 0 ) {
            while (getline(inFile6, line)) {
                if (lineNumber != lineToReplace) {
                    temp_File3 << line << endl;
                }
                lineNumber++;
            }

            // Remove the original input file
            cout << "\nAdding amount to account updated succesfully" << endl;

            temp_File3 <<  newValue << endl;
            Create_Trans2 <<  "06" << "_" << usr << "_" << checkUser(usr,user_file) << "_" << total_credit << endl;
            Create_Trans2.close();

            inFile6.close();
            temp_File3.close();

            remove("user_account.txt");

            rename("temp4.txt", "user_account.txt");

        }
        else {
            inFile6.close();
            temp_File3.close();
            //remove("temp.txt");
            cout << "\nUser does not exist" << endl;

        }


        // cout << "money after minus " << newSellerCredit << endl;

        return 0;
    }

// int main() {
//     User user1("Islam", "ST", 1000.0);
//     cout << user1.getUserName() << endl;
// }
