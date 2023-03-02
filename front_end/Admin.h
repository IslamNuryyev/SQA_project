#include <iostream>
#include <string>
#include <fstream>
#include "User.h"

using namespace std;

class Admin : public User {
// private:
//     bool isAdminLoggedIn;

public:

    void createUser(string name, string type, float credit, string user_file, string transactionFile);

};