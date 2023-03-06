#include <iostream>
#include <string>
#include <fstream>
#include "User.h"

using namespace std;

class Admin : public User {
private:
    // string encode_password(const std::string& password);
    // string decode_password(const std::string& encoded_password);


public:
    void createUser(string name,string type, string user_file, string transactionFile);

};