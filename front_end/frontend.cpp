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
    cout << "Welcome to the Auction App" << endl;
    cout << " -- Created by -- " << endl;
    cout << " -- Luis Octavo -- " << endl;
    cout << " -- Owais Najmi -- " << endl;
    cout << " -- Islam Nuryyev -- " << endl;
    cout << " -- Bhargav Parekh -- " << endl;
}

// This is where the check for the current user accounts file.
void checkCurrentUserFile() {
    // If file is empty or missing, throw an error


}

// string userInput;
int main()
{
    // cout << "Welcome to the Auction App" << endl;
    startupScreen();
    
    cout << "Enter command: ";

    // transaction type input
    string transaction;
    cin >> transaction;


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
}

void createAccount() {
    
}

