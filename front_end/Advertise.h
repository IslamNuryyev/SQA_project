#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
using namespace std;


class Advertise : public User {
    public:
    void postAdvertise (string SellerusrName, string item_name,  int numDays, int startPrice);
};