import re
import os


def mergeTransactionFiles():
    inputs = []
    # Create mac alternative path here
    for file in os.listdir("back_end/transaction_files"):
        if file.endswith(".txt"):
            inputs.append(os.path.join("back_end/transaction_files", file))
    # print(inputs)
    # Create mac alternative path here
    with open('back_end\merged_file.txt', 'w') as outfile:
        for fname in inputs:
            with open(fname) as infile:
                for line in infile:
                    # Remove the "00" from each transaction file
                    if not line.strip("\n").startswith('00'):
                        outfile.write(line)
            # outfile.write("\n")


def fetchTransactionCode(transactionLine):
    return transactionLine[:2]


def main():

    transactionCode = ""

    # Upon launch, it will merge all the transaction files in a directory
    mergeTransactionFiles()

    # After merge it will be read the combined transaction file line by line
    # readTransactionLine()

    # Open the merged transaction file
    # file1 = open('back_end\pseudo_transaction_file.txt', 'r') #windows
    file1 = open('./back_end/pseudo_transaction_file.txt', 'r')  # mac

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
            print("DEBUG: Create Initiated")

            userPartsArray = re.findall(r'\S+', line)
            username = userPartsArray[1]
            user_type = userPartsArray[2]
            credits = userPartsArray[3]
            new_value_padded = "{:0>9}".format(credits)

            # file = open('back_end\user_account.txt', 'a')  # windows
            create = open('./back_end/user_account.txt', 'a')  # mac
            username_padded = username.ljust(16)
            user_type_padded = user_type.ljust(3)
            create.write('\n' + username_padded +
                         user_type_padded + new_value_padded)

        # ISLAM
        if transactionCode == "02":
            print("DEBUG: Delete Initiated")

            deleteUserPartsArray = re.findall(r'\S+', line)
            usernameToDelete = deleteUserPartsArray[1]

            with open('./back_end/user_account.txt', 'r') as f:
                lines = f.readlines()

            # find out what line number to delete
            line_number = 0
            for line in lines:
                line_number += 1
                if (usernameToDelete == line[:len(usernameToDelete)]):
                    break

            # Remove line we want to delete from the array
            if line_number <= len(lines):
                del lines[line_number-1]

            # Override all other lines
            with open("./back_end/user_account.txt", 'w') as f:
                f.writelines(lines)

       # BHARGAV
        if transactionCode == "03":
            print("DEBUG: Advertise initiated")
            print("Printing Line 03", line)

            transaction_Adv_Array = re.findall(r'\S+', line)

            # Transaction file partitions
            Transaction_Item = transaction_Adv_Array[1]
            Transaction_Seller_User = transaction_Adv_Array[2]
            Transaction_Num_Days = transaction_Adv_Array[3]
            Transaction_initial_price = transaction_Adv_Array[4]
            # since we are first time writing this item to file, we won't have a bidder yet.
            Bidder_User = 'NONE'
            # this will be updated when user bids

            # this is the formated line with filling the empty space with spaces.
            line_to_write = '{:<20}{:<16}{:<15}{:<4}{:<7}\n'.format(
                Transaction_Item, Transaction_Seller_User, Bidder_User, Transaction_Num_Days, Transaction_initial_price)

            # with open (r'back_end\items.txt', 'a') as Itemfile: #windows
            with open(r'./back_end/items.txt', 'a') as Itemfile:  # mac

                Itemfile.write(line_to_write)
                print(line_to_write)

            Itemfile.close()

            # Add advertise code here

        # OWAIS
        if transactionCode == "04":
            # print("DEBUG: Bid initiated")

            # Add bid code initiated
            # Partition the transaction in an array of strings
            transactionLinePartsArray = re.findall(r'\S+', line)

            # The partitions are now in digestible variable pieces

            # Transaction file partitions
            TransactionFileItem = transactionLinePartsArray[1]
            TransactionFileBidder = transactionLinePartsArray[3]
            TransactionFileBid = transactionLinePartsArray[4]

            # with open(r'back_end\items.txt','r+') as itemsFile: #windows
            with open(r'./back_end/items.txt', 'r+') as itemsFile:  # mac
                # for debugging
                old = None
                new = None
                itemsFileLine = itemsFile.readlines()
                itemsFile.seek(0)
                itemsFile.truncate()
                # read each line in items file
                for currentItem in itemsFileLine:
                    # if line corresponds to item in transaction file
                    if currentItem.find(TransactionFileItem) != -1:

                        # item partitions
                        itemsLineParts = re.findall(r'\S+', currentItem)
                        itemsLineItem = itemsLineParts[0]
                        itemsLineSeller = itemsLineParts[1]
                        itemsLineBidder = itemsLineParts[2]
                        itemsLineNumDays = itemsLineParts[3]
                        itemsLineHighestBid = itemsLineParts[4]

                        # if transaction bid is greater than current highest bid, update it
                        if (float(TransactionFileBid) > float(itemsLineHighestBid)):
                            old = currentItem
                            currentItem = '{:<20}{:<16}{:<15}{:<4}{:<7}\n'.format(itemsLineItem, itemsLineSeller,
                                                                                  TransactionFileBidder, itemsLineNumDays,
                                                                                  TransactionFileBid)
                            new = currentItem

                    itemsFile.write(currentItem)
                # itemsFile.truncate()

            itemsFile.close()
            # DEBUG
            print("DEBUG: processing complete, commencing rewrite")
            if old is not None and new is not None:
                print(f"OLD: {old}NEW: {new}")
                # print(f"NEW: {new}")
            else:
                print(f"OLD: No Changes")
                print(f"NEW: No Changes")

        # FREE Bhargav REFUND
        if transactionCode == "05":
            print("Printing Line 05", line)
            UserRefundArray = re.findall(r'\S+', line)
            print(UserRefundArray)

            # 05 islam3          islam4          000005000
            buyerUserName = UserRefundArray[1]
            SelerUserName = UserRefundArray[2]
            RefCredit = int(UserRefundArray[3])

            # updating Buyer account with new credit
            with open(r'./back_end/user_account.txt', 'r') as f:
                lines = f.readlines()
                for i, line in enumerate(lines):
                    parts = line.split()
                    if parts[0] == buyerUserName:

                        parts[0] = "{:<15}".format(parts[0])

                        new_value_padded = "{:0>9}".format(
                            str(int(parts[-1]) + RefCredit))
                        parts[-1] = new_value_padded
                        print("ref credit", parts[-1])
                        lines[i] = " ".join(parts) + "\n"
            f.close()

            with open(r'./back_end/user_account.txt', "w") as f:
                f.writelines(lines)
            f.close()

            # updating Seller account with minus credit
            with open(r'./back_end/user_account.txt', 'r') as f:
                lines = f.readlines()
                for i, line in enumerate(lines):
                    parts = line.split()
                    if parts[0] == SelerUserName:

                        parts[0] = "{:<15}".format(parts[0])

                        new_value_padded = "{:0>9}".format(
                            str(int(parts[-1]) - RefCredit))
                        parts[-1] = new_value_padded
                        lines[i] = " ".join(parts) + "\n"
            f.close()

            with open(r'./back_end/user_account.txt', "w") as f:
                f.writelines(lines)
            f.close()

        # LUIS
        if transactionCode == "06":
            # print("DEBUG: Add credit initiated")

            # Partition the transaction in an array of strings
            transactionLinePartsArray = re.findall(r'\S+', line)
            # print(transactionLinePartsArray)

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
                # print("ADMIN")
                ...

            # Check if standard
            if TransactionFileUserType == "FS":
                # print("STANDARD")

                # Select the user
                # Open the user file
                # Find the user in the user account files
                targetUser = ""
                # with open (r'back_end\user_account.txt', 'r') as userAccountFile: #windows
                with open(r'./back_end/user_account.txt', 'r') as userAccountFile:  # mac
                    # data = userAccountFile.read()
                    tempUserLines = userAccountFile.readlines()

                    for targetUser in tempUserLines:
                        if targetUser.find(TransactionFileUser) != -1:

                            # Now that we found the target user in the files, partition them and assign to variable chunks
                            # print("DEBUG: " + targetUser)

                            UserAccountPartsArray = re.findall(
                                r'\S+', targetUser)
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
                            # print(howManyZeroesToAdd)
                            # Make a for loop of bunch of zeros
                            zeroString = ""
                            for _ in range(howManyZeroesToAdd):
                                zeroString = zeroString + "0"

                            # Combine the zerostring and the new credit amount
                            newCreditAmount = zeroString + str(newCreditAmount)
                            newUserAccountStatement = targetUser.replace(
                                UserAccountCredits, newCreditAmount)
                            # print(newUserAccountStatement)

            userAccountFile.close()

            # DEBUG
            print("DEBUG: processing complete, commencing rewrite")
            print("OLD: " + targetUser)
            print("NEW: " + newUserAccountStatement)

            # Note: this process is very inefficient, but it works for now
            # with open(r'back_end\user_account.txt', 'r') as file: #windows
            with open(r'./back_end/user_account.txt', 'r') as file:  # mac

                data = file.read()
                data = data.replace(targetUser, newUserAccountStatement)

            # Write the data
            # with open(r'back_end\user_account.txt', 'w') as file: #windows
            with open(r'./back_end/user_account.txt', 'w') as file:  # mac

                file.write(data)

            # DEBUG needs to be 15160 credits by the end of the modification
            file.close()

        if not line:
            break


main()
