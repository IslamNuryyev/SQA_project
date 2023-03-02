//
// Created by Bhargav on 2023-03-01.
//
#include <string>
#ifndef SQA_PROJECT_ADDCREDIT_H
#define SQA_PROJECT_ADDCREDIT_H
#include "User.h"

class AddCredit : public User {
public:
    int add_Credit (string user_name, string user_file, string transactionFile );
};

#endif //SQA_PROJECT_ADDCREDIT_H
