#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// ifstream file("user_account.txt");
// ifstream file3("user_account.txt");

class AddCredit {
    private:
    //User user;

    public:
    string checkUser(string user_name) {
        ifstream file("user_account.txt");
        string line;
        string type = "";
        char delimiter = '_';

        while (getline(file, line)) {
            string usr_name = line.substr(0, line.find(delimiter));
            string usr_type = line.substr(line.find(delimiter)+1, 2);

            if (user_name ==  usr_name) {
                if (usr_type == "FS" ) {
                    type= "FS";
                    break;
                    }
                else if (usr_type == "BS" ) {
                    type= "BS";
                    break;
                    }
                else if (usr_type == "SS" ) {
                    type = "SS";
                    break;
                }
                else if (usr_type == "AA" ) {
                    type = "AA";
                    break;
                }
            }
        }

    file.close();
    return type;
  }
    int checkCredit(string user_name) {
        ifstream file3("user_account.txt");

        string line;
        bool flag = false;
        string exist = "";
        char delimiter = '_';
        int credit_amount = 0;

        while (getline(file3, line)) {
            string usr_name = line.substr(0, line.find(delimiter));
            string usr_type = line.substr(line.find(delimiter)+1, 2);
            string amount_on_file = line.substr(line.find(delimiter)+4, 8);

            // cout<< "Hello there: " << credit_amount << endl;
            // exist = "Hello there: ";

            if (user_name ==  usr_name) {
                credit_amount = stoi(amount_on_file);

            }
        }
    file3.close();
    return credit_amount;

  }
  int locateUserLine(string name) {  // locating line to be deleted of a user
        ifstream in_File5("user_account.txt");
        if (!in_File5.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return -1;
             }
        int lineNumber = 1;
        char delimiter = '_';
        int lineToReplace;
        string line;
        if (!in_File5.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return -1;
            }

        while (getline(in_File5, line)) {
            string usr_name = line.substr(0, line.find(delimiter));
            //string usr_type = line.substr(line.find(delimiter)+1, 2);

            if (line.find(name) != string::npos) {
                // inFile.close();

                lineToReplace = lineNumber;
                //tempFile << line << endl;
                // cout << "Username located at: " << lineNumber << endl;
                return lineNumber;

            }
            lineNumber++;
            }
            in_File5.close();
            return -1;
        }

    int savetoFile (string usr, long total_credit, int currentCredit  ) {
        ofstream Create_Trans2("daily_transaction_file.txt",ios::out | ios::app);
        ifstream inFile6("user_account.txt");
        ofstream temp_File3("temp4.txt");
        string newValue; // this will contain new line with subtracted amount

         if (!inFile6.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return -1;
            }

        newValue = usr + "_" + checkUser(usr) + "_" +  to_string(total_credit);

        int lineNumber = 1;
        int lineToReplace = locateUserLine(usr);
        string line;

        if (lineToReplace > 0 ) {
            while (getline(inFile6, line)) {
                if (lineNumber != lineToReplace) {
                    temp_File3 << line << endl;
        }
        lineNumber++;
        }

         // Remove the original input file
         cout << "\nAdding amount to account updated succesfully" << endl;

        temp_File3 <<  newValue << endl;
        Create_Trans2 <<  "06" << "_" << usr << "_" << checkUser(usr) << "_" << total_credit << endl;
        Create_Trans2.close();

        inFile6.close();
        temp_File3.close();

        remove("user_account.txt");

        rename("temp4.txt", "user_account.txt");

        }
        else {
            inFile6.close();
            temp_File3.close();
            //remove("temp.txt");
            cout << "\nUser does not exist" << endl;

        }


        // cout << "money after minus " << newSellerCredit << endl;

        return 0;
    }

    int add_Credit (string user_name ) {
        string for_user =""; // admin will enter user name
        int credit_for_user; // admin will enter how much credit
        
        string check_userType = checkUser(user_name); // calling checkUser func to see if user is standard or admin
        int creditOnFile = checkCredit(user_name);

        if (check_userType == "FS" || check_userType == "BS" || check_userType == "SS" ) {
            cout << "How much credit you want to add: " << endl;
            cin >> credit_for_user;

            // cout << "total credit " << creditOnFile + credit_for_user << endl;
            long total_credit = creditOnFile + credit_for_user; 
            
            if (total_credit > 999999999 ) {
                cout << " cannot exceed credit limit of 999999999 "<< endl;
                }
            else {
                savetoFile(user_name,total_credit,creditOnFile);
                cout << total_credit << " added for " << user_name<< endl;
            }
        }
        else if (check_userType == "AA") {
            cout << "Credit for which user: " << endl;
            cin >> for_user;

            string admin_check_user = checkUser(for_user);
            if (admin_check_user == "FS" || admin_check_user == "BS" || admin_check_user == "SS") {
                // user exists
                int creditONfile = checkCredit(for_user);
                cout << "How much credit you want to add for user " << for_user << ": " << endl;
                cin >> credit_for_user;

                long admin_total_credit = credit_for_user  + creditONfile;
                                         
                if (admin_total_credit > 999999999) {
                    cout << "Admin, cannot exceed credit limit of 999999999 "<< endl;
                }
                else {
                    savetoFile(for_user,admin_total_credit,creditOnFile);
                    cout << admin_total_credit << " added for " << for_user << " by admin " << user_name << endl;
                }

            }
        }


        return 0;
    }

};



