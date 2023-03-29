import re
import os
from functions.createUser import createUser
from functions.deleteUser import deleteUser
from functions.advertise import advertise
from functions.reund import refund
from functions.addCredit import addCredit
from functions.bid import bid


def fetchTransactionCode(transactionLine):
    return transactionLine[:2]

def main():

    transactionCode = ""
    file1 = open(r'SQA_project\back_end\pseudo_transaction_file.txt', 'r') 

    # For loop to read line by line of the merged transaction file
    while True:
        # Read line by line
        line = file1.readline()
        # Fetch the transaction code (read the first two strings), it will replace the placeholder
        transactionCode = fetchTransactionCode(line)


        # ISLAM
        if transactionCode == "01":
            createUser(line)
        # ISLAM
        if transactionCode == "02":
            deleteUser(line)
        
       # BHARGAV
        if transactionCode == "03":
           advertise(line)

        # OWAIS
        if transactionCode == "04":
            bid(line)

        # FREE Bhargav REFUND
        if transactionCode == "05":
            refund(line)
        
        # LUIS
        if transactionCode == "06":
            addCredit(line)
        if not line:
            break


main()
