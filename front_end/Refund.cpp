#include <iostream>
#include <string>
#include <fstream>
#include "Refund.h"

using namespace std;


bool Refund ::takeoutfromSeller (string seller_usr, int minus_amount, string user_file) {
    ifstream inFile4(user_file);
    ofstream temp_File("temp2.txt");
    string newValue; // this will contain new line with subtracted amount
         if (!inFile4.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return false;
            }
        int currentSellerCredit = User::checkCredit(seller_usr,user_file);
        int newSellerCredit = currentSellerCredit - minus_amount;
        newValue = seller_usr + "_" + User::checkUser(seller_usr,user_file) + "_" +  to_string(newSellerCredit);
        // cout << "New user value: " << newValue << endl;

        int lineNumber = 1;
        int lineToReplace = User::locateUserLine(seller_usr,user_file);
        // cout << "line to replace number is : " << lineToReplace << endl;
        string line;

        if (lineToReplace > 0 ) {
            while (getline(inFile4, line)) {
                if (lineNumber != lineToReplace) {
                    temp_File << line << endl;
        }
        lineNumber++;
        }

         // Remove the original input file
         cout << "\nSeller account updated succesfully" << endl;

        temp_File <<  newValue << endl;

        inFile4.close();
        temp_File.close();

        remove("user_account.txt");

        rename("temp2.txt", "user_account.txt");
        return true;

        }
        else {
            inFile4.close();
            temp_File.close();
            //remove("temp.txt");
            cout << "\nUser does not exist" << endl;

            return false;

        }


        // cout << "money after minus " << newSellerCredit << endl;
        
    }

bool Refund :: addToBuyersAccount (string Buyer_usr, int plus_amount, string user_file) {
        ifstream inFile5(user_file);
        ofstream temp_File2("temp3.txt");
        string newValue; // this will contain new line with subtracted amount
         if (!inFile5.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return false;
            }
        int currentSellerCredit = User::checkCredit(Buyer_usr,user_file);
        int newSellerCredit = currentSellerCredit + plus_amount;
        newValue = Buyer_usr + "_" + User::checkUser(Buyer_usr,user_file) + "_" +  to_string(newSellerCredit);
        // cout << "New user value: " << newValue << endl;

        int lineNumber = 1;
        int lineToReplace = User::locateUserLine(Buyer_usr,user_file);
        // cout << "line to replace number is : " << lineToReplace << endl;
        string line;

        if (lineToReplace > 0 ) {
            while (getline(inFile5, line)) {
                if (lineNumber != lineToReplace) {
                    temp_File2 << line << endl;
        }
        lineNumber++;
        }

         // Remove the original input file
         cout << "\nBuyer account updated succesfully" << endl;

        temp_File2 <<  newValue << endl;

        inFile5.close();
        temp_File2.close();

        remove("user_account.txt");

        rename("temp3.txt", "user_account.txt");

        return true;

        }
        else {
            inFile5.close();
            temp_File2.close();
            //remove("temp.txt");
            cout << "\nUser does not exist" << endl;
            return false;

        }


        // cout << "money after minus " << newSellerCredit << endl;
        
    }

void Refund :: refund(string user_file, string transactionFile) {  // locating line to be deleted of a user
        string buy_userName;
        string sell_userName;
        int refund_amount;
        cout << "Enter BUYER'S username: ";
        cin >> buy_userName;

        cout << "Enter SELLER'S username: ";
        cin >> sell_userName;

        cout << "Enter amount to be refunded: ";
        cin >> refund_amount;

        bool success1 = false;
        bool success2 = false;

        //takeoutfromSeller (sell_userName,refund_amount);
        //addToBuyersAccount (buy_userName, refund_amount);

        if (User::checkUser(sell_userName,user_file) == "FS" || User::checkUser(sell_userName,user_file) == "SS" || User::checkUser(sell_userName,user_file) == "BS" ){
            success1 = takeoutfromSeller (sell_userName,refund_amount,user_file);
            
        }
        else {
            cout << "Seller account does not exist" << endl;
        }

        if (User::checkUser(buy_userName,user_file) == "FS" || User::checkUser(buy_userName,user_file) == "SS" || User::checkUser(buy_userName,user_file) == "BS" ){
            success2 = addToBuyersAccount (buy_userName,refund_amount,user_file);
        }
        else {
            cout << "Buyer account does not exist" << endl;
        }


        if (success1 == true && success2 == true ) {
            ofstream Create_Transaction(transactionFile,ios::out | ios::app);
            Create_Transaction <<  "05" << "_" << buy_userName << "_" << sell_userName << "_" << refund_amount << endl;
            Create_Transaction.close();
        }


        }
