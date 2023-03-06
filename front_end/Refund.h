#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
using namespace std;

class Refund : public User{

public:

    //bool takeoutfromSeller (string seller_usr, int minus_amount, string user_file);
    //bool addToBuyersAccount (string Buyer_usr, int plus_amount, string user_file);

    void refund(string buy_userName, string sell_userName, int refund_amount, string user_file, string transactionFile);
};
