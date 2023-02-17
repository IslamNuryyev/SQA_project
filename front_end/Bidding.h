#include <iostream>
#include <string>
#include <fstream>
//#include "User.h"
using namespace std;

ifstream file2("user_account.txt");
ifstream ticketFile("tickets.txt");

class Bidding{
    private:

    public:
    string checkUser(string user_name) {
        string line;
        string exist = "";
        char delimiter = '_';

        while (getline(file2, line)) {
            string usr_name = line.substr(0, line.find(delimiter));
            string usr_type = line.substr(line.find(delimiter)+1, 2);
            if (user_name ==  usr_name) {
                if (usr_type == "FS" || usr_type == "BS" || usr_type == "AA" ) {
                    cout << "User has bidding privilege: " << user_name << endl;
                    exist= "bidder";
                    break;
                    }
                else{
                    break;
                }
            }
        }

    file2.close();
    return exist;
  }

    int bid (string usr_name ) {
        string for_user ="";
        float credit_for_user;
        float bid_amount;
        string check_userType = checkUser(usr_name); // calling checkUser func to see if user is standard or admin

        string itemName;
        string currentBid;
        string userBidItem;

        string line;
        char delimiter = '_';
        
        //TODO
        // needs to add constrains like bidding should be higher than current bid, should be atleast 5% higher than current bid. 
        while (getline(ticketFile, line)) {
            itemName = line.substr(0, line.find(delimiter));
            currentBid = line.substr(line.find(delimiter)+16, 8);
        }
        if (check_userType == "bidder" ) {
            cout << itemName << endl;
            cout << " Select an item from above item list " << endl;
            cin >> userBidItem;
            if (userBidItem.length() > 0 ) {
                cout << "current bid price: "<< currentBid << endl;
                cout << " How much you want to bid on: " <<userBidItem << endl;
                cin >> bid_amount;

                cout << " You have succesfully bid " << bid_amount << " on " << userBidItem <<  endl;

            }
            else {
                cout << "Please select item for bidding: " << endl;
            }

        }
        else {
            cout << "You do not have bidding privilege" << endl;
        }

        return 0;
    }
    
};



