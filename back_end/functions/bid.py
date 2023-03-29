import re

def bid(line):
    transactionLineParts = re.findall(r'\S+', line)
     # Transaction file partitions
    TransactionFileItem = transactionLineParts[1]
    TransactionFileSeller = transactionLineParts[2]
    TransactionFileBidder = transactionLineParts[3]
    TransactionFileBid = transactionLineParts[4] 

    with open(r'SQA_project\back_end\items.txt', 'r') as f:
        lines = f.readlines()
    for i, line in enumerate(lines):
        if TransactionFileItem in line:
            parts = line.split()
            currentBid = float(parts[-1])
            if float(TransactionFileBid) > float(currentBid):
                newLine = '{:<20}{:<16}{:<15}{:<4}{:<7}\n'.format(parts[0],TransactionFileSeller, TransactionFileBidder, parts[3], float(TransactionFileBid))
                lines[i] = newLine
                with open(r'SQA_project\back_end\items.txt', 'w') as f:
                    f.writelines(lines)
                print('Bid updated for item {}.'.format(TransactionFileItem))
                return
            else:
                print('Bid amount is not greater than current bid amount for item {}.'.format(TransactionFileItem))
                return
    print('Item {} not found.'.format(TransactionFileItem))