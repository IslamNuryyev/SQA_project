#include <iostream>
#include <fstream>
#include <string>
#include "User.h"

class Delete : public User {
    private:  

    public:
    int deleteUser(string u_name, string type, string user_file, string transactionFile);
};