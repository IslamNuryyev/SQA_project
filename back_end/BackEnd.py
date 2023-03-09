

def mergeTransactionFiles():
    ...

def readUserAccountFile():
    ...

def readItemFile():
    ...

def readTransactionLine():
    ...


def fetchTransactionCode():
    ...




def main():

    transactionCode = "01"

    # Upon launch, it will merge all the transaction files in a directory
    mergeTransactionFiles()

    # After merge it will be read the combined transaction file line by line
    readTransactionLine()

    # For loop to read line by line of the merged transaction file
    for line in lines:

        # Fetch the transaction code (read the first two strings), it will replace the placeholder
        transactionCode = fetchTransactionCode()

        # Use the transaction code to initiate the commands

        # Initiate create
        if transactionCode == 1:
            # Open user file

            # Use the exising line as parameters to write on the user file

            # Exit
            ...




