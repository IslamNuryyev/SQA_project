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
        ofstream userFile("user_account.txt", ios::out | ios::app);
        ofstream Create_Trans("daily_transaction_file.txt",ios::out | ios::app);
        if (userFile.is_open()) 
        {
            userFile <<  newUser.getUserName() << "_" << newUser.getUserType() << "_" << newUser.getUserCredit() << endl;
            cout << "Added " << newUser.getUserName() << "_" << newUser.getUserType() << "_" << newUser.getUserCredit() <<
            " to user_account.txt" << endl;
            userFile.close();

            Create_Trans <<  "01" << "_" << newUser.getUserName() << "_" << newUser.getUserType() << "_" << checkCredit(newUser.getUserName()) << endl;
            Create_Trans.close();
        } else {
            cout << "Error: could not open user_account.txt for writing." << endl;
        }
    }

    int locateUserLine(string name) {  // locating line to be deleted of a user
        ifstream inFile("user_account.txt");
        if (!inFile.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return -1;
             }
        int lineNumber = 1;
        char delimiter = '_';
        int lineToDelete;
        string line;
        if (!inFile.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return -1;
            }

        while (getline(inFile, line)) {
            string usr_name = line.substr(0, line.find(delimiter));
            //string usr_type = line.substr(line.find(delimiter)+1, 2);

            if (line.find(name) != string::npos) {
                // inFile.close();

                lineToDelete = lineNumber;
                //tempFile << line << endl;
                cout << "Username located at: " << lineNumber << endl;
                return lineNumber;

            }
            lineNumber++;
            }
            inFile.close();
            return -1;
        }
// get current balance for a user
    int checkCredit(string user_name) {
        ifstream file3("user_account.txt");

        string line;
        bool flag = false;
        string exist = "";
        char delimiter = '_';
        int credit_amount = 0;

        while (getline(file3, line)) {
            string usr_name = line.substr(0, line.find(delimiter));
            string amount_on_file = line.substr(line.find(delimiter)+4, 8);

            if (user_name ==  usr_name) {
                credit_amount = stoi(amount_on_file);

            }
        }
    file3.close();
    return credit_amount;

  }

    int deleteUser(string u_name, string type) {  // locating line to be deleted of a user
        ifstream inFile("user_account.txt");
        ofstream Trans_file("daily_transaction_file.txt",ios::out | ios::app);

         if (!inFile.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return -1;
            }
        ofstream tempFile("temp.txt");
        int lineNumber = 1;
        int lineToDelete = locateUserLine(u_name);
        cout << "line to delete number is : " << lineToDelete << endl;
        string line;

        if (lineToDelete > 0 ) {
            while (getline(inFile, line)) {
                if (lineNumber != lineToDelete) {
                    tempFile << line << endl;
        }
        lineNumber++;
        }

         // Remove the original input file
         cout << "\nUser deleted succesfully" << endl;

        Trans_file <<  "02" << "_" << u_name << "_" << type << "_" << checkCredit(u_name) << endl;
        Trans_file.close();

        inFile.close();
        tempFile.close();

        remove("user_account.txt");

        rename("temp.txt", "user_account.txt");

        }
        else {
            inFile.close();
            tempFile.close();
            remove("temp.txt");
            cout << "\nUser does not exist" << endl;

        }


        return 0;
        }


    void addCredit(string name, float credit) {
        // code to add the given credit to the user with the given name
    }
};


