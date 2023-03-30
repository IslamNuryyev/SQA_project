import re
import os
def deleteUser(line):
    user_account_file = os.path.join("SQA_project", "back_end", "user_account.txt")
    print("DEBUG: Delete Initiated")
    deleteUserPartsArray = re.findall(r'\S+', line)
    usernameToDelete = deleteUserPartsArray[1]
    with open(user_account_file, 'r') as f_in, open(user_account_file + '.tmp', 'w') as f_out:
        for line in f_in:
            if usernameToDelete not in line:
                f_out.write(line)

    # Rename the temporary file to the original file name to overwrite the original file
    os.replace(user_account_file + '.tmp', user_account_file)
    f_in.close()