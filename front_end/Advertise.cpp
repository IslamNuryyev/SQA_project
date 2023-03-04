#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "Advertise.h"
using namespace std;

string itemName;
float minimumBid;
int numberOfDays;
// the maximum price for an item is 999.99
// string itemFile = "items.txt";
string transactionFile;
string separator = "_";


void itemNamePrompt() {
    cout << "Enter item name: ";
    cin >> itemName;

    // if itemName
}

void Advertise :: createItem(string sellerName) {
    cout << "Testing" << endl;

    cout << "Enter item name: ";
    string tempItemName;
    cin >> tempItemName
    if (tempItemName.length() > 25) {
        itemName = tempItemName.substr(0, 25);
        } else {
            itemName = tempItemName
        }
    }

    cout << "Enter starting bid: ";
    cin >> minimumBid;

    cout << "Enter days when auction is active: ";
    int tempNumberOfDays;
    cin >> tempNumberOfDays;
    if (tempNumberOfDays > 100) {
        numberOfDays = 100;
    } else {
        numberOfDays = tempNumberOfDays;
    }

    cout << "\n-------------------- Item Created! --------------------" << endl;
    cout << "--------------------    Details    --------------------" << endl;
    cout << "Item Name: " << itemName << endl;
    cout << "StartingBid: " << minimumBid << endl;
    cout << "Days: " << numberOfDays << endl;
    cout << "Seller Name: " << sellerName << endl;

    // write the item into the available items file here
    ofstream myfile;
    myfile.open("items.txt", std::ios_base::app);
    myfile << itemName << separator << sellerName << separator << "None" << separator << numberOfDays << separator << minimumBid << "\n";
    myfile.close();

    // write in the transaction file here
    myfile.open("daily_transaction_file.txt", std::ios_base::app);
    myfile << "03" << separator << itemName << separator << sellerName << separator << numberOfDays << separator << minimumBid << "\n";
    myfile.close();

}