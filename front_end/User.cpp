

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
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
        userName = name;
    }
    void User::setUserType(string type) {
        userType = type;
    }
    void User::setUserCredit(float credit) {
        userCredit = credit;
    }
    void User::setIsLoggedIn(bool loggedIn) {
        isLoggedIn = loggedIn;
    }

    string User::checkUser(string user_name, string user_file) {
        ifstream file(user_file);
        string line;
        string Returntype;

        if (file.is_open())
        {
            while (std::getline(file, line)) {
                stringstream ss(line);
                string usr, usrType;
                ss >> usr >> usrType;

                if (usr ==  user_name) {
                    if (usrType == "FS" ) {
                        Returntype ="FS";
                        break;
                    }
                    else if (usrType == "BS" ) {
                        Returntype ="BS";
                        break;
                    }
                    else if (usrType == "SS" ) {
                        Returntype ="SS";
                        break;
                    }
                    else if (usrType == "AA" ) {
                        Returntype ="AA";
                        break;
                    }
            }
        }

        file.close();
        }
        else
        {
            cerr << "LT01ERR - Error opening file." << endl;
        }

        return Returntype;
    }

    int User::checkCredit(string user_name, string user_file) {
        ifstream file3(user_file);

        string line;
        bool flag = false;
        string exist = "";
        char delimiter = ' ';
        int credit_amount = 0;

        while (getline(file3, line)) {

            stringstream ss(line);
            string usr_name, usr_type, amount_on_file;
            ss >> usr_name >> usr_type >> amount_on_file;


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
        char delimiter = ' ';
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

    int User::savetoFile (string usr, int toAddCredit, string user_file, string transactionFile ) {
        ofstream Create_Trans2(transactionFile,ios::out | ios::app);
        string newValue; // this will contain new line with subtracted amount


        string fillUser = usr + string(15 - usr.length(), ' ');
        //newValue = fillUser + " " + checkUser(usr,user_file) + " " +  to_string(total_credit);

        int lineNumber = 1;
        int lineToReplace = locateUserLine(usr, user_file);
        string line;

        if (lineToReplace > 0 ) {
            cout << "\n Credit amount willl be added" << endl;

            //temp_File3 <<  fillUser << " " << checkUser(usr,user_file) << " " << std::setw(9) << std::setfill('0') << to_string(total_credit) << endl;
            
            Create_Trans2 <<  "06" << " " << fillUser << " " << checkUser(usr,user_file) << " " << std::setw(9) << std::setfill('0') << to_string(toAddCredit) << endl;
            Create_Trans2.close();

        }
        else {
            cout << "\nUser does not exist" << endl;

        }

        return 0;
    }
