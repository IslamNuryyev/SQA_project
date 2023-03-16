import re

def mergeTransactionFiles():
    ...

def fetchTransactionCode(transactionLine):
    return transactionLine[:2];



def main():

    transactionCode = ""

    # Upon launch, it will merge all the transaction files in a directory
    mergeTransactionFiles()

    # After merge it will be read the combined transaction file line by line
    # readTransactionLine()

    # Open the merged transaction file
    file1 = open('back_end\pseudo_transaction_file.txt', 'r')

    # For loop to read line by line of the merged transaction file
    while True:
        # Read line by line
        line = file1.readline()
        # Fetch the transaction code (read the first two strings), it will replace the placeholder
        transactionCode = fetchTransactionCode(line)

        # Use the transaction code to initiate the commands
        print(line)

        # ISLAM
        if transactionCode == "01":
            
            #print("DEBUG: Create initiated")

            # Add create code here
            # Open the user file
            
            # Fetch the username from the line

            # Apply the user to the user file

            # Apply the user type and credits

            # Format
            ...

        # ISLAM
        if transactionCode == "02":
            #print("DEBUG: Delete Initiated")

            # Add delete code here
            ...

        # BHARGAV
        if transactionCode == "03":
            print("DEBUG: Advertise initiated")
            print("Printing Line 03",line)

            transaction_Adv_Array = re.findall(r'\S+', line)

            # Transaction file partitions
            Transaction_Item = transaction_Adv_Array[1]
            Transaction_Seller_User = transaction_Adv_Array[2]
            Transaction_Num_Days = transaction_Adv_Array[3]
            Transaction_initial_price = transaction_Adv_Array[4]
            Bidder_User= 'NONE' # since we are first time writing this item to file, we won't have a bidder yet.
                                #this will be updated when user bids


            # this is the formated line with filling the empty space with spaces.
            line_to_write='{:<20}{:<16}{:<15}{:<4}{:<7}\n'.format(Transaction_Item, Transaction_Seller_User, Bidder_User, Transaction_Num_Days, Transaction_initial_price) 

            with open (r'back_end\items.txt', 'a') as Itemfile:
                 Itemfile.write(line_to_write)
                 print(line_to_write)
            
            Itemfile.close()


            # Add advertise code here

        # OWAIS
        if transactionCode == "04":
            #print("DEBUG: Bid initiated")

            # Add bid code initiated
            ...

        # FREE
        if transactionCode == "05":
            print("Printing Line 05",line)

            # transaction_REF_Array = re.findall(r'\S+', line)

            # # Transaction file partitions
            # # 05 islam3          islam4          000005000
            # REF_Buyer_user = transaction_Adv_Array[1]
            # REF_Seller_User = transaction_Adv_Array[2]
            # REF_Credit = transaction_Adv_Array[3]

            # #update Buyer info in User_account file
            # with open (r'back_end\items.txt', 'r+') as Itemfile:




            #print("DEBUG: Refund initiated")

            # Add refund code here

        # LUIS
        if transactionCode == "06":
            #print("DEBUG: Add credit initiated")

            # Partition the transaction in an array of strings
            transactionLinePartsArray = re.findall(r'\S+', line)
            #print(transactionLinePartsArray)

            # The partitions are now in digestible variable pieces

            # Transaction file partitions
            TransactionFileUser = transactionLinePartsArray[1]
            TransactionFileUserType = transactionLinePartsArray[2]
            TransactionFileCredits = transactionLinePartsArray[3]

            # User account partitions
            UserAccountUser = ""
            UserAccountUserType = ""
            UserAccountCredits = ""
            
            # New credit amount
            newCreditAmount = ""
            newUserAccountStatement = ""

            # Add credit code here
            # Check if admin
            if TransactionFileUserType == "AA":
                #print("ADMIN")
                ...

            # Check if standard
            if TransactionFileUserType == "FS":
                #print("STANDARD")
                
                # Select the user
                # Open the user file
                # Find the user in the user account files
                targetUser = ""
                with open (r'back_end\user_account.txt', 'r') as userAccountFile:
                    # data = userAccountFile.read()
                    tempUserLines = userAccountFile.readlines()

                    for targetUser in tempUserLines:
                        if targetUser.find(TransactionFileUser) != -1:

                            # Now that we found the target user in the files, partition them and assign to variable chunks
                            #print("DEBUG: " + targetUser)

                            UserAccountPartsArray = re.findall(r'\S+', targetUser)
                            UserAccountUser = UserAccountPartsArray[0]
                            UserAccountUserType = UserAccountPartsArray[1]
                            UserAccountCredits = UserAccountPartsArray[2]

                            # Now that we have both variables of credits from the transaction file and the user accounts file, add them here
                            # Turn the string numbers into int
                            TFC = int(TransactionFileCredits)
                            UAC = int(UserAccountCredits)
                            # Add them
                            newCreditAmount = TFC + UAC
                            # Add the necessary zeroes
                            # Since the user credit limits are only 9 zeroes, take that into account when adding it back to the file
                            howManyZeroesToAdd = 9 - len(str(newCreditAmount))
                            #print(howManyZeroesToAdd)
                            # Make a for loop of bunch of zeros
                            zeroString = ""
                            for _ in range(howManyZeroesToAdd):
                                zeroString = zeroString + "0"

                            # Combine the zerostring and the new credit amount
                            newCreditAmount = zeroString + str(newCreditAmount)
                            newUserAccountStatement = targetUser.replace(UserAccountCredits, newCreditAmount)
                            #print(newUserAccountStatement)
            
            userAccountFile.close()

            # DEBUG
            print("DEBUG: processing complete, commencing rewrite")
            print("OLD: " + targetUser)
            print("NEW: " + newUserAccountStatement)

            # Note: this process is very inefficient, but it works for now
            with open(r'back_end\user_account.txt', 'r') as file:
                data = file.read()
                data = data.replace(targetUser, newUserAccountStatement)
            
            # Write the data
            with open(r'back_end\user_account.txt', 'w') as file:
                file.write(data)

            # DEBUG needs to be 15160 credits by the end of the modification
            file.close()

        if not line:
            break

main()




