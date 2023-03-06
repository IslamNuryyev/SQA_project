#include <iostream>
#include <string>
#include <fstream>
#include "AddCredit.h"
#include "Refund.h"
#include "Delete.h"
#include "Bidding.h"
#include "Admin.h"
#include "Advertise.h"
#include <sstream>

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
bool ExistingUser(string user_name) {
    ifstream file("user_account.txt");
    string line;
    bool userExist = false;

    if (file.is_open()){
        while (std::getline(file, line)){
                stringstream ss(line);
                string usr, usrType;
                ss >> usr >> usrType;

                if (usr ==  user_name) {
                    userExist= true;
                    }
        }

        file.close();
    }
    else
    {
        cerr << "Error opening file." << endl;
    }

    return userExist;
  }


string checkUserMain(string user_name) {
    ifstream file("user_account.txt");
    string line;
    string Returntype;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
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
        cerr << "Error opening file." << endl;
    }

    return Returntype;
  }
//bhargav         SS 412818

int main( int argc, char** argv) {
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
            if (checkUserMain(username) == "AA") {
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
            else if (checkUserMain(username) == "FS") 
            {
                cout << "Select from below options" << endl;
                cout << "          bid         " << endl;
                cout << "        advertise         " << endl;
                cout << "        addcredit         " << endl;
                cout << "          logout         " << endl;
                cout << "        \n         " << endl;
            }
            else if (checkUserMain(username) == "SS") 
            {
                cout << "Select from below options" << endl;
                cout << "        advertise         " << endl;
                cout << "        addcredit         " << endl;
                cout << "          logout         " << endl;
                cout << "        \n         " << endl;
            }
            else if (checkUserMain(username) == "BS") 
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
                if (checkUserMain(username) == "AA") {
                    Admin addNewUser;

                    string newUserName;
                    string newUserType;
                    int newUserCredit;

                    cout << "Enter new user username: " << endl;
                    cin >> newUserName;
                    if (ExistingUser(newUserName) == true) {
                        cout << "User already exists" << endl;
                        break;
                    }
                    else if (newUserName.length() > 15) {
                            cout << "Username cannot exceed length 15 character" << endl;
                            break;
                    }

                    cout << "Enter new user user type: " << endl;
                    cin >> newUserType;
                    if ((newUserType != "AA" && newUserType != "FS" && newUserType != "SS" && newUserType != "BS")) {
                        cout << "Enter AA FS BS or SS as user type" << endl;
                        break;
                    }
                    else {
                        Admin addNewUser;
                        addNewUser.createUser(newUserName,newUserType,argv[1], argv[3] );
                        break;


                    }
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
            if (checkUserMain(username) == "AA") {
                Delete UserToDelete;
                string del_username;
                cout << "Enter username to be deleted: ";
                cin >> del_username;
                UserToDelete.deleteUser(username,del_username,checkUserMain(del_username), argv[1], argv[3]);
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
            if (checkUserMain(username) != "BS") {
                string item_name;
                int num_days;
                double start_price;

                cout << "Whats the item name: ";
                cin.ignore();
                getline(cin, item_name);
                if (item_name.length() > 25 ) {
                    cout << "Item name cannot be more than 25 characters" << endl;
                    break;
                }
                cout << "Starting price: " << endl;
                cin >> start_price;
                if (start_price > 999.99) {
                    cout << "Price cannot be more than 999.99" << endl;
                    break;
                }
                cout << "Auctioning for how many days: " << endl;
                cin >> num_days;
                if (num_days > 100) {
                    cout << "Item cannot be placed in auction for more than 100 days" << endl;
                    break;
                }
                if(item_name.length() <= 25 && start_price < 999 && num_days < 100 ) {
                    Advertise putAdvertise;
                    putAdvertise.postAdvertise(username,item_name,num_days,start_price);
                }
                else {
                    cout << "somethinf went wrong" << endl;
                }
            
            }
            else {
                cout << "you do not have Item Advertise privilege" << endl;
                cout << "Select other option" << endl;
            }

            break;

        // bid transaction code
        case 6:
            if (checkUserMain(username) == "AA" || checkUserMain(username) == "FS" || checkUserMain(username) == "BS") {
                Bidding newBid;
                newBid.bid(username,argv[1], argv[2], argv[3]);
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
            if (checkUserMain(username) == "AA") {
                string buy_usr;
                string sell_usr;
                int refund_amount;
                cout << "Enter Buyer username: " << endl;
                cin >> buy_usr;
                string checkBuyer = checkUserMain(buy_usr);
                if (checkBuyer.length() == 0) {
                    cout << "Buyer account does not exist" << endl;
                    break;
                } 
                cout << "Enter Seller username: " << endl;
                cin >> sell_usr;

                string checkSeller = checkUserMain(sell_usr);
                if (checkSeller.length() == 0) {
                    cout << "Seller account does not exist" << endl;
                    break;
                }
                cout << "Enter amount to be refunded: ";
                cin >> refund_amount;

                if (checkBuyer.length() > 0 && checkSeller.length() > 0 ) {
                    Refund newRefund;
                    newRefund.refund(buy_usr,sell_usr,refund_amount, argv[1], argv[3]);
                    break;
                }
                else {
                    cout << "refund cannot be processed" << endl;
                }
            }
            else {
                cout << "You do not have permission for Refund !! " << endl;
                cout << "Select appropriate option from above " << endl;
            }
            break;

        // addcredit transaction code
        case 8:
            AddCredit newCredit;
            newCredit.add_Credit(username,argv[1], argv[3]);

            break;
        }
    } while (transactionCode != 2);
    }


// islam           AA 999999
// islam           FS 100002
// baparekh3       AA 1234
// bhar            AA 000035323
// user02          AA 00001e+06
// islam4          SS 000092504
// owais           FS 000120237
// user01          SS 00000-999
// bhhhdd          AA 000004354
// islam3          BS 000135037

