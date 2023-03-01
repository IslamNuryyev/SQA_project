#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Refund {

public:

    string checkUser(string user_name) {
        ifstream file_user("user_account.txt");
        string line;
        string type = "";
        char delimiter = '_';
        bool exist = false;
        while (getline(file_user, line)) {
            string usr_name = line.substr(0, line.find(delimiter));
            string usr_type = line.substr(line.find(delimiter)+1, 2);
            if (user_name ==  usr_name) {
                    exist = true;
                    if (usr_type == "FS" ) {
                        type= "FS";
                        break;
                        }
                    else if (usr_type == "BS") {
                        type= "BS";
                        break;

                    }
                    else if (usr_type == "SS") {
                        type= "SS";
                        break;
                    }
                    else if (usr_type == "AA"){
                        type = "AA";
                        break;
                    }
                    // else {
                    //     cout << "User does not exist" << endl;
                    //      }
                }
            }
        file_user.close();
            //if (usr_name.size() =)
        return type;
  }


    
    int locateUserLine(string name) {  // locating line to be deleted of a user
        ifstream inFile("user_account.txt");
        if (!inFile.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return -1;
             }
        int lineNumber = 1;
        char delimiter = '_';
        int lineToReplace;
        string line;
        if (!inFile.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return -1;
            }

        while (getline(inFile, line)) {
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
            inFile.close();
            return -1;
        }
// get current balance for a user
    int checkCredit(string user_name) {
        ifstream file3("user_account.txt");

        string line;
        bool flag = false;
        string exist = "";
        char delimiter = '_';
        int credit_amount = 0;

        while (getline(file3, line)) {
            string usr_name = line.substr(0, line.find(delimiter));
            string amount_on_file = line.substr(line.find(delimiter)+4, 8);

            if (user_name ==  usr_name) {
                credit_amount = stoi(amount_on_file);

            }
        }
    file3.close();
    return credit_amount;

  }

    bool takeoutfromSeller (string seller_usr, int minus_amount) {
        ifstream inFile4("user_account.txt");
        ofstream temp_File("temp2.txt");
        string newValue; // this will contain new line with subtracted amount
         if (!inFile4.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return false;
            }
        int currentSellerCredit = checkCredit(seller_usr);
        int newSellerCredit = currentSellerCredit - minus_amount;
        newValue = seller_usr + "_" + checkUser(seller_usr) + "_" +  to_string(newSellerCredit);
        // cout << "New user value: " << newValue << endl;

        int lineNumber = 1;
        int lineToReplace = locateUserLine(seller_usr);
        // cout << "line to replace number is : " << lineToReplace << endl;
        string line;

        if (lineToReplace > 0 ) {
            while (getline(inFile4, line)) {
                if (lineNumber != lineToReplace) {
                    temp_File << line << endl;
        }
        lineNumber++;
        }

         // Remove the original input file
         cout << "\nSeller account updated succesfully" << endl;

        temp_File <<  newValue << endl;

        inFile4.close();
        temp_File.close();

        remove("user_account.txt");

        rename("temp2.txt", "user_account.txt");
        return true;

        }
        else {
            inFile4.close();
            temp_File.close();
            //remove("temp.txt");
            cout << "\nUser does not exist" << endl;

            return false;

        }


        // cout << "money after minus " << newSellerCredit << endl;
        
    }

    bool addToBuyersAccount (string Buyer_usr, int plus_amount) {
        ifstream inFile5("user_account.txt");
        ofstream temp_File2("temp3.txt");
        string newValue; // this will contain new line with subtracted amount
         if (!inFile5.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return false;
            }
        int currentSellerCredit = checkCredit(Buyer_usr);
        int newSellerCredit = currentSellerCredit + plus_amount;
        newValue = Buyer_usr + "_" + checkUser(Buyer_usr) + "_" +  to_string(newSellerCredit);
        // cout << "New user value: " << newValue << endl;

        int lineNumber = 1;
        int lineToReplace = locateUserLine(Buyer_usr);
        // cout << "line to replace number is : " << lineToReplace << endl;
        string line;

        if (lineToReplace > 0 ) {
            while (getline(inFile5, line)) {
                if (lineNumber != lineToReplace) {
                    temp_File2 << line << endl;
        }
        lineNumber++;
        }

         // Remove the original input file
         cout << "\nBuyer account updated succesfully" << endl;

        temp_File2 <<  newValue << endl;

        inFile5.close();
        temp_File2.close();

        remove("user_account.txt");

        rename("temp3.txt", "user_account.txt");

        return true;

        }
        else {
            inFile5.close();
            temp_File2.close();
            //remove("temp.txt");
            cout << "\nUser does not exist" << endl;
            return false;

        }


        // cout << "money after minus " << newSellerCredit << endl;
        
    }

    void refund() {  // locating line to be deleted of a user
        string buy_userName;
        string sell_userName;
        int refund_amount;
        cout << "Enter BUYER'S username: ";
        cin >> buy_userName;

        cout << "Enter SELLER'S username: ";
        cin >> sell_userName;

        cout << "Enter amount to be refunded: ";
        cin >> refund_amount;

        bool success1 = false;
        bool success2 = false;

        //takeoutfromSeller (sell_userName,refund_amount);
        //addToBuyersAccount (buy_userName, refund_amount);

        if (checkUser(sell_userName) == "FS" || checkUser(sell_userName) == "SS" || checkUser(sell_userName) == "BS" ){
            success1 = takeoutfromSeller (sell_userName,refund_amount);
            
        }
        else {
            cout << "Seller account does not exist" << endl;
        }

        if (checkUser(buy_userName) == "FS" || checkUser(buy_userName) == "SS" || checkUser(buy_userName) == "BS" ){
            success2 = addToBuyersAccount (buy_userName,refund_amount);
        }
        else {
            cout << "Buyer account does not exist" << endl;
        }


        if (success1 == true && success2 == true ) {
            ofstream Create_Transaction("daily_transaction_file.txt",ios::out | ios::app);
            Create_Transaction <<  "05" << "_" << buy_userName << "_" << sell_userName << "_" << refund_amount << endl;
            Create_Transaction.close();
        }


        }


    // void addCredit(string name, float credit) {
    //     // code to add the given credit to the user with the given name
    // }
};


