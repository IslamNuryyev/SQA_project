import re
import os
from functions.createUser import createUser
from functions.deleteUser import deleteUser
from functions.advertise import advertise
from functions.refund import refund
from functions.addCredit import addCredit
from functions.bid import bid


def fetchTransactionCode(transactionLine):
    return transactionLine[:2]

def main():
    user_account_file = os.path.join("SQA_project", "back_end", "user_account.txt")
    item_file = os.path.join("SQA_project", "back_end", "user_account.txt")

    transactionCode = ""

    transactonFile = os.path.join("SQA_project", "back_end", "pseudo_transaction_file.txt")
    file1 = open(transactonFile, 'r') 
    

    # For loop to read line by line of the merged transaction file
    while True:
        # Read line by line
        line = file1.readline()
        # Fetch the transaction code (read the first two strings), it will replace the placeholder
        transactionCode = fetchTransactionCode(line)


        # ISLAM
        if transactionCode == "01":
            createUser(line,user_account_file)
            #...
        # ISLAM
        if transactionCode == "02":
            
            deleteUser(line,user_account_file)
        
       # BHARGAV
        if transactionCode == "03":
           #...
           advertise(line,item_file)

        # OWAIS
        if transactionCode == "04":
            #...
            bid(line,item_file)

        # FREE Bhargav REFUND
        if transactionCode == "05":
            #...
            refund(line,user_account_file)
        
        # LUIS
        if transactionCode == "06":
            #...
            addCredit(line, user_account_file)
        if not line:
            break


main()
