#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream file("user_account.txt");

class AddCredit{
    private:
    //User user;

    public:
    string checkUser(string user_name) {
        string line;
        string exist = "";
        char delimiter = '_';

        while (getline(file, line)) {
            string usr_name = line.substr(0, line.find(delimiter));
            string usr_type = line.substr(line.find(delimiter)+1, 2);

            if (user_name ==  usr_name) {
                if (usr_type == "FS" || usr_type == "BS" || usr_type == "SS" ) {
                    cout << "User is Standard: " << user_name << endl;
                    exist= "standard";
                    break;
                    }
                else{
                    cout << user_name << " is Admin" << endl;
                    exist = "admin";
                    break;
                }
            }
        }

    file.close();
    return exist;
  }

    int add_Credit (string username ) {
        string for_user =""; // admin will enter user name
        float credit_for_user; // admin will enter how much credit
        
        string check_userType = checkUser(username); // calling checkUser func to see if user is standard or admin

        if (check_userType == "standard" ) {
            cout << "How much credit you want to add: " << endl;
            cin >> credit_for_user;
            cout << credit_for_user << " added for " << username<< endl;
        }
        else if (check_userType == "admin") {
            cout << "Credit for which user: " << endl;
            cin >> for_user;
            cout << "How much credit: " << endl;
            cin >> credit_for_user;

            cout << credit_for_user << " Credit added for " << for_user << endl;
        }

        return 0;
    }
    
};



