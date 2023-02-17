#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
using namespace std;
//***************************************************************
//                   GLOBAL FUNCTIONS
//***************************************************************
void saveToFile() {
    
}

//***************************************************************
//                   SELLER FUNCTIONS
//***************************************************************
class Seller {

    protected:
    string itemName;
    int startingPrice;

    public:
    void createItem() {
        cout << "-- Create Item Initiated -- " << endl;
        cout << "Item Name: ";
        cin >> itemName;
        return;
    }

    void sellItem() {
        cout << "-- Sell Item Initiated -- " << endl;
        cout << "What item are you selling? ";
        cin >> itemName;
        return;
    }
};

class Advertise : public Seller {
    public:
    void postAdvertise(){
        cout << "-- Advertise Post Initiated -- " << endl;
        cout << "Select item to advertise: ";
        cin >> itemName;
        return;
    }
    void saveToFile(){}
    bool isNonStandard(){}
};

class Refund {

    string targetRefundUser;
    float currency;

    public:
    void issueRefund() {
        isAdmin(3);
        cout << "Refund initiated. Type user to issue a refund: ";
        cin >> targetRefundUser;
        doesUserExist();
        cout << "User validated, input amount of credits: ";
        cin >> currency;
    }
    bool isAdmin(int userType){
        return 1;
    }
    bool doesUserExist() {

    }
    void transferFunds() {
        cout << "Transfer function called!" << endl;
        return;
    }
    void saveToFile(){
        cout << "Saving..." << endl;
        sleep(10);
        cout << "Done!" << endl;
    }
};

/*
int main() {
    Seller user1;
    user1.createItem();
    user1.sellItem();
};
*/