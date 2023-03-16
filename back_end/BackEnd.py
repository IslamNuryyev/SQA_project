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
        print("-"*50)
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
            #print("DEBUG: Advertise initiated")

            # Add advertise code here
            ...

        # OWAIS
        if transactionCode == "04":
            #print("DEBUG: Bid initiated")

            # Add bid code initiated
            # Partition the transaction in an array of strings
            transactionLinePartsArray = re.findall(r'\S+', line)
            
            # The partitions are now in digestible variable pieces

            # Transaction file partitions
            TransactionFileItem = transactionLinePartsArray[1]
            TransactionFileBidder = transactionLinePartsArray[3]
            TransactionFileBid = transactionLinePartsArray[4]

            with open(r'back_end\items.txt','r+') as itemsFile:
                itemsFileLine = itemsFile.readlines()
                itemsFile.seek(0)
                itemsFile.truncate()
                # read each line in items file
                for currentItem in itemsFileLine:
                    # if line corresponds to item in transaction file
                    if currentItem.find(TransactionFileItem) != -1:

                        old = currentItem # used for debuggin below
                        new = None # used for debigging
                        
                        # item partitions
                        itemsLinePartsArray = re.findall(r'\S+', currentItem)
                        itemsLineBidder = itemsLinePartsArray[2]
                        itemsLineHighestBid = itemsLinePartsArray[4]
                        
                        # if transaction bid is greater than current highest bid, update it
                        if(float(TransactionFileBid) > float(itemsLineHighestBid)):
                            # update highest bid 
                            currentItem = currentItem.replace(itemsLineHighestBid, TransactionFileBid)
                            # update highest bidder
                            currentItem = currentItem.replace(itemsLineBidder, TransactionFileBidder)
                            new = currentItem
                            
                    itemsFile.write(currentItem)
                # itemsFile.truncate()

            itemsFile.close()
            # DEBUG
            print("DEBUG: processing complete, commencing rewrite")
            print(f"OLD: {old}")
            if new is not None:
                print(f"NEW: {new}")
            else:
                print(f"NEW: no changes")

            # # Note: this process is very inefficient, but it works for now
            # with open(r'back_end\items.txt', 'r') as file:
            #     data = file.read()
            #     data = data.replace(currentItem, newItemStatement)

            # # Write the data
            # with open(r'back_end\items.txt', 'w') as file:
            #     file.write(data)

            # # DEBUG needs to be 15160 credits by the end of the modification
            # file.close()

        # FREE
        if transactionCode == "05":
            #print("DEBUG: Refund initiated")

            # Add refund code here
            ...

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




