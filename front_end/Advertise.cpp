#include <iostream>
#include <string>
#include <fstream>
#include "Advertise.h"

void Advertise :: postAdvertise (string SellerusrName, string item_name, int minBid, int numDays, int startPrice, int currBid) {

     ofstream AdvertiseFile("availableItems.txt", ios::out | ios::app);
    //  ofstream Cr_Trans("daily_transaction_file.txt",ios::out | ios::app);
        if (AdvertiseFile.is_open()) 
        {
           
            AdvertiseFile << item_name  << "_" << SellerusrName << "_" << "TEST" << "_" << numDays << "_" << "TEST" << endl;
            
            cout << "Added " << item_name << " to user_account.txt" << endl;
            AdvertiseFile.close();

            // Cr_Trans <<  "01" << "_" << newUser.getUserName() << "_" << newUser.getUserType() << "_" << checkCredit(newUser.getUserName(),user_file) << endl;
            // Create_Trans.close();
        } else {
            cout << "Error: could not open user_account.txt for writing." << endl;
        }

}