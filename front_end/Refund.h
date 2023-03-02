#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
using namespace std;

class Refund : public User {

public:

    bool takeoutfromSeller (string seller_usr, int minus_amount, string user_file);

    bool addToBuyersAccount (string Buyer_usr, int plus_amount, string user_file);

    void refund(string user_file, string transactionFile);

    // void addCredit(string name, float credit) {
    //     // code to add the given credit to the user with the given name
    // }
};
