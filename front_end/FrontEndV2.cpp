#include <iostream>
#include <string>
#include <fstream>
#include "AddCredit.h"
#include "Bidding.h"
// #include "User.h"
#include "Admin.h"
#include "Refund.h"

using namespace std;

void login (bool isLoggedIn) {
    string username;
    if (isLoggedIn) {
     cout << "Already logged in" << endl;
    } else {
        cout << "Enter username:" << endl; 
        cin >> username;
    }
}


void startupScreen() {
    cout << "***************************************************************" << endl;
    cout << "Welcome to the Auction App" << endl;
    cout << " -- Created by     -- " << endl;
    cout << " -- Luis Octavo    -- " << endl;
    cout << " -- Owais Najmi    -- " << endl;
    cout << " -- Islam Nuryyev  -- " << endl;
    cout << " -- Bhargav Parekh -- " << endl;
    cout << "***************************************************************" << endl;
}

// This is where the check for the current user accounts file.
void checkCurrentUserFile() {
    // If file is empty or missing, throw an error


}

void mainMenu() {

}


string checkUser(string user_name) {
    ifstream file("user_account.txt");
    string line;
    string type = "";
    char delimiter = '_';
    bool exist = false;
    while (getline(file, line)) {
        string usr_name = line.substr(0, line.find(delimiter));
        string usr_type = line.substr(line.find(delimiter)+1, 2);
        if (user_name ==  usr_name) {
                exist = true;
                if (usr_type == "FS" ) {
                    type= "FS";
                    break;
                    }
                else if (usr_type == "BS") {
                    type= "BS";
                    break;

                }
                else if (usr_type == "SS") {
                    type= "SS";
                    break;
                }
                else if (usr_type == "AA"){
                    type = "AA";
                    break;
                }
                // else {
                //     cout << "User does not exist" << endl;
                //      }
            }
        }
    file.close();
        //if (usr_name.size() =)
    return type;
  }


// string userInput;
int main( int argc, char** argv)
{
    // cout << "Welcome to the Auction App" << endl;
    startupScreen();
    
    // User variables
    string username;
    string transaction;
    int transactionCode;
    bool isLoggedIn = false;
    // Text command is now turned into numerical values, to be used in switch statement to navigate specific commands.
    do {

        //***************************************************************
        // transaction type input
        cout << "\nEnter command: \n";
        // Main menu command
        cin >> transaction;
        
        // transaction type classification
        // add text redundancy later
        if (transaction == "login") {
            transactionCode = 1;
        } 
        else if (transaction == "logout") {
            transactionCode = 2;
        }
        else if (transaction == "create") {
            transactionCode = 3;
        }
        else if (transaction == "delete") {
            transactionCode = 4;
        }
        else if (transaction == "advertise") {
            transactionCode = 5;
        }
        else if (transaction == "bid") {
            transactionCode = 6;
        }
        else if (transaction == "refund") {
            transactionCode = 7;
        }
        else if (transaction == "addcredit") {
            transactionCode = 8;
        }
        //***************************************************************

        switch (transactionCode) {
        // login transaction code
        case 1:
            // asks for the username
            cout << "Enter username: \n";
            cin >> username;
            isLoggedIn = true;
            if (checkUser(username) == "AA") {
                cout << "Select from below options" << endl;
                cout << "        create         " << endl;
                cout << "        delete         " << endl;
                cout << "        advertise         " << endl;
                cout << "          bid         " << endl;
                cout << "         refund         " << endl;
                cout << "        addcredit         " << endl;
                cout << "          logout         " << endl;
                cout << "        \n         " << endl;

            }
            else if (checkUser(username) == "FS") 
            {
                cout << "Select from below options" << endl;
                cout << "          sell         " << endl;
                cout << "          bid         " << endl;
                cout << "        advertise         " << endl;
                cout << "        addcredit         " << endl;
                cout << "          logout         " << endl;
                cout << "        \n         " << endl;
            }
            else if (checkUser(username) == "SS") 
            {
                cout << "Select from below options" << endl;
                cout << "        advertise         " << endl;
                cout << "        addcredit         " << endl;
                cout << "          logout         " << endl;
                cout << "        \n         " << endl;
            }
            else if (checkUser(username) == "BS") 
            {
                cout << "Select from below options" << endl;
                cout << "          bid         " << endl;
                cout << "        addcredit         " << endl;
                cout << "          logout         " << endl;
                cout << "        \n         " << endl;
            }
            else {
                 cout << "User does not exist" << endl;
            }

            break;
        // logout transaction code
        case 2:
            if (isLoggedIn == true) {
                cout << "Logout successful!" << endl;
                break;
            } else {
                cout << "Invalid logout" << endl;
                // since this is an invalid logout, it will not proceed
                transactionCode = 1;
                break;
            }
        // create transaction code
        case 3:
            if (isLoggedIn == false) {
                cout << "Invalid command, you are not logged in" << endl;
                break;
            }
            else {
                if (checkUser(username) == "AA") {
                    Admin addNewUser;

                    string newUserName;
                    string newUserType;
                    int newUserCredit;

                    cout << "Enter new user username: " << endl;
                    cin >> newUserName;
                    cout << "Enter new user user type: " << endl;
                    cin >> newUserType;
                    cout << "Enter new user initial credit: " << endl;
                    cin >> newUserCredit;

                    addNewUser.createUser(newUserName,newUserType,newUserCredit);
                    break;
                }
                else {
                cout << "You do not have permission to Create a User !! " << endl;
                cout << "Select appropriate option from above " << endl;
                break;
            }
            break;
            }

        // delete transaction code
        case 4:
        {
            if (checkUser(username) == "AA") {
                Admin UserToDelete;
                string del_username;
                cout << "Enter username to be deleted: ";
                cin >> del_username;
                UserToDelete.deleteUser(del_username,checkUser(del_username));
                break;
            }
            else {
                cout << "You do not have permission to Delete a User !! " << endl;
                cout << "Select appropriate option from above " << endl;
                break;
            }
            break;
        }


        // advertise transaction code
        case 5:

            break;

        // bid transaction code
        case 6:
            if (checkUser(username) == "AA" || checkUser(username) == "FS" || checkUser(username) == "BS") {
                Bidding newBid;
                newBid.bid(username);
                break;
            }
            else {
                cout << "Seller acounts cannot bid " << endl;;
                cout << "Select approprate option from above " << endl;
                break;
            }
            break;

        // refund transaction code
        case 7:
            if (checkUser(username) == "AA") {
                Refund newRefund;
                newRefund.refund();
                break;
            }
            else {
                cout << "You do not have permission for Refund !! " << endl;
                cout << "Select appropriate option from above " << endl;
            }
            break;

        // addcredit transaction code
        case 8:
            AddCredit add_credit;
            add_credit.add_Credit(username);

            break;
        }
    } while (transactionCode != 2);
}

// islam_AA_999999
// islam_FS_100002
// owais_FS_100005
// islam4_SS_99504
// islam3_BS_100503
// bhargav_SS_100505

