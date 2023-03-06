#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Advertise.h"

void Advertise :: postAdvertise (string SellerusrName, string item_name,  int numDays, double startPrice) {
    string modifiedItemmName;
        
    for (int i = 0; i < item_name.length(); i++) {
        if (item_name[i] == ' ') {
            modifiedItemmName += '_';
            } else {
                modifiedItemmName += item_name[i];
                }
    }

     //ofstream AdvertiseFile("items.txt", ios::out | ios::app);
     ofstream Cr_Trans("daily_transaction_file.txt",ios::out | ios::app);

        string fillItemName = modifiedItemmName + string(25 - modifiedItemmName.length(), ' ');
        string fillSeller  = SellerusrName + string(15 - SellerusrName.length(), ' ');
        if (Cr_Trans.is_open()) 
        {
            //AdvertiseFile << fillItemName  << " " << fillSeller << " " << "NONE" << " " << std::setw(3) << std::setfill('0') << numDays << " " << std::setw(6) << std::setfill('0') << startPrice << endl;
            
            // cout << "Added " << item_name << " to user_account.txt" << endl;
            //AdvertiseFile.close();
            // cout << "price is: " << startPrice << endl; 
            Cr_Trans <<  "03" << " " << fillItemName << " " << fillSeller << " " << std::setw(3) << std::setfill('0') << numDays << " " << std::setw(6) << std::setfill('0') << startPrice << endl;
            Cr_Trans.close();
            cout << "Added " << item_name << " to transaction file" << endl;
        } else {
            cout << "Error: could not open user_account.txt for writing." << endl;
        }

}