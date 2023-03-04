#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Admin.h"

using namespace std;

void Admin :: createUser(string name, string type, float credit, string user_file, string transactionFile) {
        // code to create a new user with the given name, type, and credit
        ///User newUser(name, type, credit);
        string fillUser = name + string(15 - name.length(), ' ');

        int precision = 2;

        std::stringstream ss;
        ss << std::fixed << std::setprecision(precision) << credit;

        // save new user to user_account.txt
        ofstream userFile(user_file, ios::out | ios::app);
        ofstream Create_Trans(transactionFile,ios::out | ios::app);
        if (userFile.is_open()) 
        {
            userFile <<  fillUser << " " << type << " " << std::setw(9) << std::setfill('0') << credit << endl;
            cout << "Added " << fillUser << " " << type << " " << credit <<
            " to user_account.txt" << endl;
            userFile.close();

            Create_Trans <<  "01" << " " << fillUser << "_" << type << "_" << checkCredit(name,user_file) << endl;
            Create_Trans.close();
        } else {
            cout << "Error: could not open user_account.txt for writing." << endl;
        }
    }
    


