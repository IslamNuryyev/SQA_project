import re
import os

def addCredit(line, file):
    transactionLinePartsArray = re.findall(r'\S+', line)
    TransactionFileUser = transactionLinePartsArray[1]
    TransactionFileUserType = transactionLinePartsArray[2]
    TransactionFileCredits = transactionLinePartsArray[3]
    

        # Open the user account file for reading
    with open(file, 'r') as f:
    #with open(r'SQA_project\back_end\user_account.txt', 'r') as f:
        lines = f.readlines()

    # Find the line with the user's account information
    user_line_index = -1
    for i, line in enumerate(lines):
        if line.startswith(TransactionFileUser):
            user_line_index = i
            break

    # If the user exists, update their credit
    if user_line_index >= 0:
        user_info = lines[user_line_index].split()
        new_credit = float(user_info[2]) + float(TransactionFileCredits)
        lines[user_line_index] = f"{TransactionFileUser:15} {TransactionFileUserType:02} {new_credit:09} password\n"
        print("ADD CREDIT succesfull")

    # If the user doesn't exist, add a new line with their information
    else:
        print("Use does not exist\n")

    # Write the updated file contents back to the file
    with open(file, 'w') as f:
        f.writelines(lines)