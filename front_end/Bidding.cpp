#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include "Bidding.h"
using namespace std;


int Bidding :: getBidPrice (string userBidItem,string avai_item) {
    ifstream item_file(avai_item);
    string line;
    int returnbIdPrice;
    while (getline (item_file,line)) {
        stringstream ss(line);
        // reading each string of a line in items.txt file
        string itemname, sellername, biddername, numdays, itembidprice;
        ss >> itemname >> sellername >> biddername >>numdays>> itembidprice;
        if (userBidItem.compare(itemname) == 0 ){
            returnbIdPrice =  stoi(itembidprice);
        }
    }
    if (returnbIdPrice == 0 ) {
        cout << "item does not exist" << endl;
    }
    item_file.close();
    return returnbIdPrice;
}

string Bidding :: getSeller (string userBidItem,string avai_item) {
    ifstream item_file2(avai_item);
    string line;
    string  returnSeller;
    while (getline (item_file2,line)) {
        stringstream ss(line);
        // reading each string of a line in items.txt file
        string itemname, sellername, biddername, numdays, itembidprice;
        ss >> itemname >> sellername >> biddername >>numdays>> itembidprice;
        //cout << "out "<<  userBidItem << endl;
        //cout << "out "<< itemname << endl;
        if (userBidItem.compare(itemname) == 0 ){
             //cout << "in "<< userBidItem << endl;
            //cout <<"in " <<  itemname << endl;
            returnSeller =  sellername;
        }
    }
    if (returnSeller.length() == 0 ) {
        cout << "Seller not on file does not exist" << endl;
    }
    item_file2.close();
    return returnSeller;
}

void Bidding :: bid (string usr_name, string user_files, string avai_item, string transactionFile ) {
        ifstream ticketFile(avai_item);
        ofstream Cr_Trans(transactionFile,ios::out | ios::app);
        string for_user ="";
        float credit_for_user;
        double bid_amount;
        string check_userType = User::checkUser(usr_name,user_files); // calling checkUser func to see if user is standard or admin

        string itemName;
        int currentBid;
        string userBidItem;

        string line;
        std::string item_names;
        
        //TODO
        // needs to add constrains like bidding should be higher than current bid, should be atleast 5% higher than current bid. 
        while (getline(ticketFile, line)) {
            std::istringstream iss(line);
            iss >> item_names;
            cout << item_names << endl;
        }
            cout << " Select an item from above item list " << endl;
            cin >> userBidItem;
            currentBid =  getBidPrice(userBidItem,avai_item);
            if (currentBid > 0 ) {
                cout << "current bid price: "<< currentBid << endl;
                cout << " How much you want to bid on: " <<userBidItem << endl;
                cin >> bid_amount;

                double minBidAmount = (currentBid*0.05) + currentBid;
                if (bid_amount > minBidAmount) {
                    string fillItem = userBidItem + string(19 - userBidItem.length(), ' ');
                    string sellerName =  getSeller (userBidItem,avai_item);
                    string fillSeller = sellerName + string(15 - sellerName.length(), ' '); 
                    string fillBidder = usr_name + string(15 - usr_name.length(), ' '); s

                    cout << " Your bid amount of " << bid_amount << " on " << userBidItem << "is added to file" << endl;
                    string amounttoString = to_string(bid_amount);
                    Cr_Trans <<  "04" << " " << fillItem << " " << fillSeller << " "<< fillBidder << " " << std::setfill('0') << std::setw(6) << amounttoString << endl;
                    Cr_Trans.close();
                }
                else {
                    cout << " Bid atleast " << (currentBid*0.05) + currentBid << " on " << userBidItem <<  endl;
                }

            }
            else {
                cout << "Please select item for bidding: " << endl;
            }

        ticketFile.close();
    }