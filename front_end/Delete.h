#include <iostream>
#include <fstream>
#include <string>
#include "Admin.h"

class Delete {
    private:
        string username;
        string usertype;
        float userCredit;

        
        User user;    

    public:
    Delete() : username(""), usertype(""), userCredit(0.0) {}

    Delete(string name, string type, float credit) {
        this->username = name;
        this->usertype = type;
        this->userCredit = credit;
    }

    void deleteUser() {
        cout << "Enter username: ";
        cin >> username;

        cout << "Enter user type: ";
        cin >> usertype;

        cout << "Enter user credits: ";
        cin >> userCredit;
        
        ifstream inFile("user_account.txt");
        ofstream outFile("temp.txt");
        string line;
        // string userToDelete = username + "_"+usertype+"_"+ to_string(userCredit);

        while (getline(inFile, line))
        {
            if(line != username + "_"+usertype+"_"+ to_string(userCredit)){
                outFile << line << endl;
            }
        }
        inFile.close();
        outFile.close();

        remove("user_account.txt");
        rename("temp.txt", "user_account.txt");

        cout << "User " << username << "_" << usertype << "_" << userCredit << " deleted successfully" << endl;
        
    }

    void saveToFile(){
        // may not need this function
    }

    void isAdmin(){
                // TODO : currently need a way to allow an admin to access this classes variables
    }
};