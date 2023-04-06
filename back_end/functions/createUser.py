import re
import os
def createUser(line,user_account_file ):
    userPartsArray = re.findall(r'\S+', line)
    username = userPartsArray[1]
    user_type = userPartsArray[2]
    credits = userPartsArray[3]
    exists = False
        # Check if user already exists
    with open(user_account_file, 'r') as f:
        lines = f.readlines()
        for line in lines:
            if line.startswith(username):
                exists = True
                print("User exist\n")
    f.close()
    
    if (exists == False):
        with open(user_account_file, 'a+') as f:
                    # Create new line with given values
            new_value_padded = "{:0>9}".format(credits)
            username_padded = username.ljust(15)
            user_type_padded = user_type.ljust(2)
            new_line = f"{username_padded} {user_type_padded} {new_value_padded} password\n"
            f.write(new_line)
            print("CREATE USER Succesfull")
        f.close()