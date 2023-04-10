# #!/bin/bash

dir="../../src"
num_sessions=1
CURRENT_USERS="iofiles/current_users_accounts.txt"
AVAIL_ITEMS="iofiles/available_items.txt"
sessions_dir="scripts/sessions"
MERGE_FILE_TO_STORE="../iofiles/merged_TransactionFile.txt"

mkdir -p "session_Output"
cd "$dir"


for ((i=1; i<=1; i++)) # FOR RUNNING dailyScript.sh directly
#for ((i=1; i<=5; i++)) # FOR RUNNING USING weeklyScript.sh
do
  for session_file in "$sessions_dir"/"day${i}"/*; do
    # Set the output file for this session
    output_file="scripts/session_Output/session_transactions.txt"
    
    # Run the Front End using the input file and save the output to the transaction file
    echo "Running auction_system with input file $session_file..."
    # pwd
    ./auction_system iofiles/current_users_accounts.txt iofiles/available_items.txt iofiles/daily_transaction.txt < $session_file >> $output_file
  done
done

# Merge all files starting with daily_ into one file
echo "Merging files..."
cd "transactionFiles"  # navigate to transactionFile folder
cat daily_*.txt > "$MERGE_FILE_TO_STORE"

# removing files after they have been merged
rm daily_*.txt

echo "Merge complete."
echo "Deleted session transaction files."


# # Running backEnd on the merged file
cd ../../../
cd back_end
echo "Running Backend."
python3 BackEndV2.py
echo "Backend running complete."

# Running backEnd on the merged file
# cd ../../
# cd back_end
# python3 BackEndV2.py
