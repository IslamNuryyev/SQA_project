

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

        # Initiate create

        # ISLAM
        if transactionCode == "01":
            print(line)
            print("DEBUG: Create initiated")

            # Add create code here
            # Open the user file
            
            # Fetch the username from the line

            # Apply the user to the user file

            # Apply the user type and credits

            # Format

        # ISLAM
        if transactionCode == "02":
            print("DEBUG: Delete Initiated")

            # Add delete code here

        # BHARGAV
        if transactionCode == "03":
            print("DEBUG: Advertise initiated")

            # Add advertise code here

        # OWAIS
        if transactionCode == "04":
            print("DEBUG: Bid initiated")

            # Add bid code initiated

        # FREE
        if transactionCode == "05":
            print("DEBUG: Refund initiated")

            # Add refund code here

        # LUIS
        if transactionCode == "06":
            print("DEBUG: Add credit initiated")

            # Add credit code here

        else:
            ...

        if not line:
            break

main()




