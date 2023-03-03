#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "Advertise.h"
using namespace std;


string itemName;
float minimumBid;
int numberOfDays;
// string itemFile = "items.txt";
string transactionFile;
string separator = "_";

void Advertise :: createItem(string sellerName) {
    cout << "Testing" << endl;

    cout << "Enter item name: ";
    cin >> itemName;

    cout << "Enter starting bid: ";
    cin >> minimumBid;

    cout << "Enter days when auction is active: ";
    cin >> numberOfDays;

    cout << "\n-------------------- Item Created! --------------------" << endl;
    cout << "--------------------    Details    --------------------" << endl;
    cout << "Item Name: " << itemName << endl;
    cout << "StartingBid: " << minimumBid << endl;
    cout << "Days: " << numberOfDays << endl;
    cout << "Seller Name: " << sellerName << endl;

    // write the item into the file here
    ofstream myfile;
    myfile.open("items.txt", std::ios_base::app);
    myfile << "03" << separator << itemName << separator << sellerName << separator << numberOfDays << separator << minimumBid << "\n";
    myfile.close();

}