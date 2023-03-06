#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
using namespace std;

// ifstream file2("user_account.txt");
// ifstream ticketFile("tickets.txt");

class Bidding : public User{
    private:

    public:

    void bid (string usr_name, string user_files, string avai_item, string transactionFile );
    int getBidPrice (string userBidItem,string avai_item);
    string getSeller (string userBidItem,string avai_item); 
    
};
