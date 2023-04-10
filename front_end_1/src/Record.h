#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>


/* CONSTANTS DECLARATIONS */
// Account Types
const std::string ADMIN = "AA";
const std::string FULL_STANDARD = "FS";
const std::string SELL_STANDARD = "SS";
const std::string BUY_STANDARD = "BS";

// Transaction Codes
const std::string LOGOUT_TRANSACTION_CODE = "00";
const std::string CREATE_TRANSACTION_CODE = "01";
const std::string DELETE_TRANSACTION_CODE = "02";
const std::string ADVERTISE_TRANSACTION_CODE = "03";
const std::string BID_TRANSACTION_CODE = "04";
const std::string REFUND_TRANSACTION_CODE = "05";
const std::string ADDCREDIT_TRANSACTION_CODE = "06";
const std::string RESETPASSWORD_TRANSACTION_CODE = "07";

// Minimums and Maximums
const int MAX_CREDIT = 999999;
const int MIN_CREDIT = 0;
const int MAX_CREDIT_ADD = 1000;
const int MAX_DURATION = 999;
const int MAX_USERNAME_LENGTH = 15;
const int SALT = 4;

/* RECORD DELCARATIONS */
struct ITEM_RECORD {
	std::string itemName;
    std::string seller;
	std::string buyer;
	float highestBid = 0;
	float minBid = 0;
    int duration = 1;
};

// struct BID_RECORD {
// 	std::string itemName;
//     std::string seller;
// 	std::string buyer;
// 	float highestBid = 0;
// 	float minBid = 0;
//     int duration = 1;
// };

struct REFUND_RECORD {
	std::string buyer;
	std::string seller;
	float amount;
};

struct USER_RECORD {
    std::string username;
	std::string accountType;
	float credit = 0;
	std::string password;
};



/* RECORD FUNCTIONS */
// Puts a record (item record) into a string
inline std::string recordToString(ITEM_RECORD itemRecord){
    std::stringstream itemStream;
	// itemStream << itemRecord.itemName << " " << itemRecord.seller << " " << itemRecord.duration << " " << itemRecord.highestBid;
	//03 car                user01       N/A          32 23 
	itemStream << std::setw(19) << std::left << itemRecord.itemName << std::setw(13) << std::left << itemRecord.seller << std::setw(13) << std::left << itemRecord.buyer << std::setw(4) << std::left << itemRecord.duration<< " " << std::setw(10) << std::left << itemRecord.highestBid;
    std::cout << itemStream.str() << std::endl;
	std::string itemInfo = itemStream.str();
	return itemInfo;
}

// Overloads the recordToString function to accept a refund record
inline std::string recordToString(REFUND_RECORD refundRecord){
    std::stringstream refundStream;
	// refundStream << refundRecord.buyer << " " << refundRecord.seller << " " << refundRecord.amount;
	refundStream << std::setw(15) << std::left << refundRecord.buyer << std::setw(15) << std::left << refundRecord.seller << std::setw(9) << std::left << refundRecord.amount;

	std::string refundInfo = refundStream.str();
	return refundInfo;
}

// Overloads the recordToString function to accept a user record
inline std::string recordToString(USER_RECORD userRecord){
    std::stringstream userStream;
	// userStream << userRecord.username << " " << userRecord.accountType << " " << userRecord.credit << " " << userRecord.password;
	// 01 dsdd           FS000000teww00000000000
	// userStream << std::setw(15) << std::left << userRecord.username << std::setw(2) << std::left << userRecord.accountType << std::setfill('0') << std::setw(6) << userRecord.credit << std::setw(15) << std::left << userRecord.password;
	// userStream << std::setw(15) << std::left << userRecord.username << " "  << userRecord.accountType << " "<< std::setfill('0') << std::setw(6) << userRecord.credit << " "<< std::setw(15) << std::left << userRecord.password;
	userStream << std::setw(15) << std::left << userRecord.username << " " << std::setw(2) << std::left << userRecord.accountType << " " << std::setw(6) << std::left << userRecord.credit << std::setw(10) << std::left << userRecord.password;

	std::string userInfo = userStream.str();
	return userInfo;
}

#endif