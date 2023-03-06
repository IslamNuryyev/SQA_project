#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Delete.h"
using namespace std;


int Delete :: deleteUser(string currentUser, string u_name, string type,string user_file, string transactionFile) {  // locating line to be deleted of a user
        ofstream Trans_file(transactionFile,ios::out | ios::app);

        string userExists = User::checkUser(u_name,user_file);
        if (Trans_file.is_open()) {
            if (currentUser == u_name ) {
                cout << "DEL02ERR - Cannot delete current user" << endl;
            }
            else if (userExists.length()>0) {
                cout << "\nUsername " << u_name << " will be deleted"  << endl;
                string fillUser = u_name + string(15 - u_name.length(), ' ');
                Trans_file <<  "02" << " " << fillUser << " " << type << " " << std::setw(9) << std::setfill('0') << checkCredit(u_name,user_file) << endl;
                Trans_file.close();

            }
            else {
                cout << "DEL03ERR - User does not exist" << endl;
            }
        }

        else {
            cout << "\nUser does not exist" << endl;
            }
        return 0;
        }