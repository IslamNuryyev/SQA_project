# #!/bin/bash

# # Set the directory containing the files to merge
# dir="../src"
# num_sessions=1
# CURRENT_USERS=../iofiles/current_users_accounts.txt
# AVAIL_ITEMS=../iofiles/available_items.txt
# sessions_dir="./sessions"
# MERGE_FILE_TO_STORE="../iofiles/merged_TransactionFile.txt"

# mkdir -p "session_Output"

# for session_file in "$sessions_dir"/*; do
  
#   # Set the output file for this session
#   output_file="session_Output/session_transactions.txt"
  
#   # Run the Front End using the input file and save the output to the transaction file
#   echo "Running auction_system with input file $session_file..."
#   ../auction_system ../iofiles/current_users_accounts.txt ../iofiles/available_items.txt ../iofiles/daily_transaction.txt < $session_file >> $output_file
# done

# # Merge all files starting with daily_ into one file
# echo "Merging files..."
# cat daily_*.txt > "$MERGE_FILE_TO_STORE"

# echo "Merge complete."

dir="../../src"
num_sessions=1
CURRENT_USERS="iofiles/current_users_accounts.txt"
AVAIL_ITEMS="iofiles/available_items.txt"
sessions_dir="scripts/sessions"
MERGE_FILE_TO_STORE="../iofiles/merged_TransactionFile.txt"

mkdir -p "session_Output"
cd "$dir"
for session_file in "$sessions_dir"/*; do
  
  # Set the output file for this session
  output_file="scripts/session_Output/session_transactions.txt"
  
  # Run the Front End using the input file and save the output to the transaction file
  echo "Running auction_system with input file $session_file..."
  # pwd
  ./auction_system iofiles/current_users_accounts.txt iofiles/available_items.txt iofiles/daily_transaction.txt < $session_file >> $output_file
done

# Merge all files starting with daily_ into one file
echo "Merging files..."
cd "transactionFiles"  # navigate to transactionFile folder
cat daily_*.txt > "$MERGE_FILE_TO_STORE"

echo "Merge complete."


# Running backEnd on the merged file
cd ../../../
cd back_end
python3 BackEndV2.py


# Running backEnd on the merged file
# cd ../../
# cd back_end
# python3 BackEndV2.py
