import re
import os

def refund(line,user_account_file):
    UserRefundArray = re.findall(r'\S+', line)
   # print(UserRefundArray)
    flagToExit = False

            # 05 testBSUser      testSSUser      000541.00
    buyerUserName = UserRefundArray[1]
    SelerUserName = UserRefundArray[2]
    RefCredit = float(UserRefundArray[3])


    print("initiating Seller update REFUND")
    with open(user_account_file, 'r') as f:
        lines = f.readlines()
        for i, line in enumerate(lines):
            parts = line.split()
            if (parts[0] == SelerUserName):
                if (float(parts[2]) - float(RefCredit)) > 0:
                    parts[0] = "{:<15}".format(parts[0])
                    new_value_padded = "{:0>9}".format(str(float(parts[2]) - RefCredit))
                    parts[2] = new_value_padded
                    parts[3] = "teww"
                    lines[i] = " ".join(parts) + "\n"
                else:
                    print("User ", SelerUserName, " DOES NOT have enough credit for to refund ",RefCredit  )
                    flagToExit = True
                    break
    f.close()

    if (flagToExit == False):
            with open(user_account_file, "w") as f:
                f.writelines(lines)
            f.close()

    print("initiating Buyr update REFUND")

    if (flagToExit == False):
        with open(user_account_file, 'r') as f:
            lines = f.readlines()
            for i, line in enumerate(lines):
                if not line.strip():
                    continue
                parts = line.split()
                if parts[0] == buyerUserName:
                    parts[0] = "{:<15}".format(parts[0])
                    new_value_padded = "{:0>9}".format(str(float(parts[2]) + RefCredit))
                    parts[2] = new_value_padded
                    parts[3] = "teww"
                    lines[i] = " ".join(parts) + "\n"
        f.close()
        with open(user_account_file, "w") as f:
            f.writelines(lines)
            print("REFUND Succesfull")
        f.close()
    else:
        print("Buyer update REFUND failed")
