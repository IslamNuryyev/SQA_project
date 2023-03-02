//
// Created by Bhargav on 2023-03-01.
//
#include <iostream>
#include <string>
#include <fstream>
#include "AddCredit.h"
#include "User.h"
using namespace std;


int AddCredit::add_Credit(string user_name, string user_file, string transactionFile) {
    string for_user =""; // admin will enter username
    int credit_for_user; // admin will enter how much credit

    string check_userType = User::checkUser(user_name,user_file); // calling checkUser func to see if user is standard or admin
    int creditOnFile = User::checkCredit(user_name, user_file);

    if (check_userType == "FS" || check_userType == "BS" || check_userType == "SS" ) {
        cout << "How much credit you want to add: " << endl;
        cin >> credit_for_user;

        // cout << "total credit " << creditOnFile + credit_for_user << endl;
        long total_credit = creditOnFile + credit_for_user;

        if (total_credit > 999999999 ) {
            cout << " cannot exceed credit limit of 999999999 "<< endl;
        }
        else {
            User::savetoFile(user_name,total_credit,creditOnFile,user_file,transactionFile);
            cout << total_credit << " added for " << user_name<< endl;
        } // user_account.txt    daily_transaction_file.txt
    }
    else if (check_userType == "AA") {
        cout << "Credit for which user: " << endl;
        cin >> for_user;

        string admin_check_user = User::checkUser(for_user,user_file);
        if (admin_check_user == "FS" || admin_check_user == "BS" || admin_check_user == "SS") {
            // user exists
            int creditONfile = User::checkCredit(for_user,user_file);
            cout << "How much credit you want to add for user " << for_user << ": " << endl;
            cin >> credit_for_user;

            long admin_total_credit = credit_for_user  + creditONfile;

            if (admin_total_credit > 999999999) {
                cout << "Admin, cannot exceed credit limit of 999999999 "<< endl;
            }
            else {
                User::savetoFile(for_user,admin_total_credit,creditOnFile,user_file,transactionFile);
                cout << admin_total_credit << " added for " << for_user << " by admin " << user_name << endl;
            }

        }
    }


    return 0;
}
