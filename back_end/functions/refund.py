import re

def refund(line):
    print("Printing Line 05", line)
    UserRefundArray = re.findall(r'\S+', line)
    print(UserRefundArray)

            # 05 islam3          islam4          000005000
    buyerUserName = UserRefundArray[1]
    SelerUserName = UserRefundArray[2]
    RefCredit = int(UserRefundArray[3])

            # updating Buyer account with new credit
    with open(r'SQA_project\back_end\user_account.txt', 'r') as f:
        lines = f.readlines()
        for i, line in enumerate(lines):
            parts = line.split()
            if parts[0] == buyerUserName:
                parts[0] = "{:<15}".format(parts[0])
                new_value_padded = "{:0>9}".format(str(int(parts[-1]) + RefCredit))
                parts[-1] = new_value_padded
                print("ref credit", parts[-1])
                lines[i] = " ".join(parts) + "\n"
    f.close()

    with open(r'SQA_project\back_end\user_account.txt', "w") as f:
        f.writelines(lines)
    f.close()

            # updating Seller account with minus credit
    with open(r'SQA_project\back_end\user_account.txt', 'r') as f:
        lines = f.readlines()
        for i, line in enumerate(lines):
            parts = line.split()
            if parts[0] == SelerUserName:
                parts[0] = "{:<15}".format(parts[0])
                new_value_padded = "{:0>9}".format(str(int(parts[-1]) - RefCredit))
                parts[-1] = new_value_padded
                lines[i] = " ".join(parts) + "\n"
    f.close()
    with open(r'SQA_project\back_end\user_account.txt', "w") as f:
        f.writelines(lines)
    f.close()