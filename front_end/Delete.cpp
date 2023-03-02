#include <iostream>
#include <fstream>
#include <string>
#include "Delete.h"
using namespace std;


int Delete :: deleteUser(string u_name, string type,string user_file, string transactionFile) {  // locating line to be deleted of a user
    ifstream inFile(user_file);
    ofstream Trans_file(transactionFile,ios::out | ios::app);

        if (!inFile.is_open()) {
        cout << "Error: Unable to open file!" << endl;
        return -1;
        }
    ofstream tempFile("temp.txt");
    int lineNumber = 1;
    int lineToDelete = User::locateUserLine(u_name,user_file);
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

    Trans_file <<  "02" << "_" << u_name << "_" << type << "_" << User::checkCredit(u_name,user_file) << endl;
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