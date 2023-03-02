#include <iostream>
#include <string>
#include <fstream>
#include "Bidding.h"
using namespace std;

int Bidding :: bid (string usr_name, string user_files, string avai_item ) {
        ifstream ticketFile(avai_item);
        string for_user ="";
        float credit_for_user;
        int bid_amount;
        string check_userType = User::checkUser(usr_name,user_files); // calling checkUser func to see if user is standard or admin

        string itemName;
        int currentBid;
        string userBidItem;

        string line;
        char delimiter = '_';
        
        //TODO
        // needs to add constrains like bidding should be higher than current bid, should be atleast 5% higher than current bid. 
        while (getline(ticketFile, line)) {
            itemName = line.substr(0, line.find(delimiter));
            currentBid = stoi(line.substr(line.find(delimiter)+16, 8));
        }
        if (check_userType == "AA" || check_userType == "FS" || check_userType == "BS" ) {
            cout << itemName << endl;
            cout << " Select an item from above item list " << endl;
            cin >> userBidItem;
            if (userBidItem.length() > 0 ) {
                cout << "current bid price: "<< currentBid << endl;
                cout << " How much you want to bid on: " <<userBidItem << endl;
                cin >> bid_amount;

                if (bid_amount > ((currentBid*0.05) + currentBid)) {
                    cout << " You have succesfully bid " << bid_amount << " on " << userBidItem <<  endl;
                }
                else {
                    cout << " Bid atleast " << (currentBid*0.05) + currentBid << " on " << userBidItem <<  endl;
                }

            }
            else {
                cout << "Please select item for bidding: " << endl;
            }

        }
        else {
            cout << "You do not have bidding privilege" << endl;
        }
        ticketFile.close();

        return 0;
    }