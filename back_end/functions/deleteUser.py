import re
import os
def deleteUser(line):
    print("DEBUG: Delete Initiated")
    deleteUserPartsArray = re.findall(r'\S+', line)
    usernameToDelete = deleteUserPartsArray[1]
    with open(r'SQA_project\back_end\user_account.txt', 'r') as f_in, open(r'SQA_project\back_end\user_account.txt' + '.tmp', 'w') as f_out:
        for line in f_in:
            if usernameToDelete not in line:
                f_out.write(line)

    # Rename the temporary file to the original file name to overwrite the original file
    os.replace(r'SQA_project\back_end\user_account.txt' + '.tmp', r'SQA_project\back_end\user_account.txt')
    f_in.close()