#include <iostream>
#include <fstream>
#include <string>
#include "Delete.h"
using namespace std;


int Delete :: deleteUser(string currentUser, string u_name, string type,string user_file, string transactionFile) {  // locating line to be deleted of a user
        ifstream inFile(user_file);
        ofstream Trans_file(transactionFile,ios::out | ios::app);

         if (!inFile.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return -1;
            }
        ofstream tempFile("temp.txt");
        int lineNumber = 1;
        int lineToDelete = User::locateUserLine(u_name,user_file);
        // cout << "line to delete number is : " << lineToDelete << endl;
        string line;
        cout << "currentUser: " << currentUser << "user to delete: " << u_name << endl;
        if (lineToDelete > 0 && currentUser != u_name ) {
            while (getline(inFile, line)) {
                if (lineNumber != lineToDelete ) {
                    tempFile << line << endl;
        }
        lineNumber++;
        }

         // Remove the original input file
         cout << "\nUser deleted succesfully" << endl;

        Trans_file <<  "02" << "_" << u_name << "_" << type << "_" << User::checkCredit(u_name,user_file) << endl;
        Trans_file.close();
        inFile.close();
        tempFile.close();

        remove("user_account.txt");
        rename("temp.txt", "user_account.txt");

        }
        else {
            if (currentUser == u_name ) {
                cout << "Cannot delete current user" << endl;
            }
            else{
                cout << "\nUser does not exist" << endl;
            }
            inFile.close();
            tempFile.close();
            remove("temp.txt");

        }


        return 0;
        }