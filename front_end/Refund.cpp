#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
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

        string fillUser = seller_usr + string(15 - seller_usr.length(), ' ');

        //newValue = seller_usr + "_" + User::checkUser(seller_usr,user_file) + "_" +  to_string(newSellerCredit);
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

        temp_File << fillUser << " " << User::checkUser(seller_usr,user_file) << " " << std::setw(9) << std::setfill('0') << to_string(newSellerCredit) << endl;

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

        string fillUser = Buyer_usr + string(15 - Buyer_usr.length(), ' ');

       // newValue = fillUser + " " + User::checkUser(Buyer_usr,user_file) + " " +  to_string(newSellerCredit);
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

        temp_File2 <<  fillUser << " " << User::checkUser(Buyer_usr,user_file) << " " << std::setw(9) << std::setfill('0') << to_string(newSellerCredit) << endl;

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
// islam           AA 999999
// islam           FS 100002
// baparekh3       AA 1234
// owais           FS 121237
// islam4          SS 97504
// bhar            AA 000035323
// bhargav         SS 000412840
// parekhbhrg      FS 000045454
// islam3          BS 000106940

        
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

        if (User::checkUser(sell_userName,user_file) == "FS" || User::checkUser(sell_userName,user_file) == "SS" ){
            success1 = takeoutfromSeller (sell_userName,refund_amount,user_file);
            if (User::checkUser(buy_userName,user_file) == "FS" || User::checkUser(buy_userName,user_file) == "BS" ){
                success2 = addToBuyersAccount (buy_userName,refund_amount,user_file);
        }
            
        }
        else {
            cout << "One of the account does not exist" << endl;
            success1 = false; 
            success2 = false;
        }


        if (success1 == true && success2 == true ) {
            string fillBuyUser = buy_userName + string(15 - buy_userName.length(), ' ');
            string fillSellerUser = sell_userName + string(15 - sell_userName.length(), ' ');
            ofstream Create_Transaction(transactionFile,ios::out | ios::app);
            Create_Transaction <<  "05" << " " << fillBuyUser << " " << fillSellerUser << " " << std::setw(9) << std::setfill('0') << to_string(refund_amount) << endl;
            Create_Transaction.close();
        }


        }
