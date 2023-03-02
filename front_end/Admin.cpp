#include <iostream>
#include <string>
#include <fstream>
#include "Admin.h"

using namespace std;

void Admin :: createUser(string name, string type, float credit, string user_file, string transactionFile) {
        // code to create a new user with the given name, type, and credit
        User newUser(name, type, credit);

        // save new user to user_account.txt
        ofstream userFile(user_file, ios::out | ios::app);
        ofstream Create_Trans(transactionFile,ios::out | ios::app);
        if (userFile.is_open()) 
        {
            userFile <<  newUser.getUserName() << "_" << newUser.getUserType() << "_" << newUser.getUserCredit() << endl;
            cout << "Added " << newUser.getUserName() << "_" << newUser.getUserType() << "_" << newUser.getUserCredit() <<
            " to user_account.txt" << endl;
            userFile.close();

            Create_Trans <<  "01" << "_" << newUser.getUserName() << "_" << newUser.getUserType() << "_" << checkCredit(newUser.getUserName(),user_file) << endl;
            Create_Trans.close();
        } else {
            cout << "Error: could not open user_account.txt for writing." << endl;
        }
    }
    


