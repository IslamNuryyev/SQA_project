#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Admin.h"

using namespace std;

void Admin :: createUser(string name,string type, string user_file, string transactionFile) {
        // code to create a new user with the given name, type, and credit
        ///User newUser(name, type, credit);
        string fillUser = name + string(15 - name.length(), ' ');

        ofstream Create_Trans(transactionFile,ios::out | ios::app);
        if (Create_Trans.is_open()) 
        {
            //userFile <<  fillUser << " " << type << " " << std::setw(9) << std::setfill('0') << credit << endl;
            cout << "User " << name <<  " Succesfully Added to transcation file " << endl;
            //userFile.close();

            Create_Trans <<  "01" << " " << fillUser << " " << type << " "<< 0.0 << endl;
            Create_Trans.close();
        } else {
            cout << "Error: could not open user_account.txt for writing." << endl;
        }
    }
    


