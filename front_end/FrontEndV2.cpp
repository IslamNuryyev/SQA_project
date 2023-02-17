#include <iostream>
#include <string>
#include <fstream>

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

// string userInput;
int main()
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
        cout << "Enter command: ";
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
            cout << "Enter username: ";
            cin >> username;
            isLoggedIn = true;
            break;
        // logout transaction code
        case 2:
            if (isLoggedIn == true) {
                cout << "Logout successful!" << endl;
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

            break;

        // delete transaction code
        case 4:

            break;


        // advertise transaction code
        case 5:

            break;

        // bid transaction code
        case 6:

            break;

        // refund transaction code
        case 7:

            break;

        // addcredit transaction code
        case 8:

            break;
        }
    } while (transactionCode != 2);
    
    /*
    if (transaction == "login")
    {

        // reads in the currrent user accounts file
        ifstream file("user_account.txt");
        string line;
        
        // login boolean 
        bool isLoggedIn = false;

        while (getline(file, line))
        {   
            cout << "user = " << line << endl;
        }

        // asks for the username
        cout << "Enter username: ";
        string username;
        cin >> username;
        file.close();


        // reads in the available items file
        ifstream file2("tickets.txt");
        while (getline(file2, line))
        {   
            cout << "-- Here are the available items --" << endl;
            cout << "item = " << line << endl;
        }

        cout << "Enter a transaction code: ";
        string code;
        cin >> code;
        
        if ("logout" == code)
        {
            exit(0);
        }

    } else {
        
    }
    */
}

void createAccount() {
    
}