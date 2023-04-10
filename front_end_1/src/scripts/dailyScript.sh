# #!/bin/bash

# # Set the directory containing the files to merge
# dir="../src"
# num_sessions=1
# CURRENT_USERS=../iofiles/current_users_accounts.txt
# AVAIL_ITEMS=../iofiles/available_items.txt
# sessions_dir="./sessions"
# MERGE_FILE_TO_STORE=../iofiles/

# mkdir -p "session_Output"

# for session_file in "$sessions_dir"/*; do
  
#   # Set the output file for this session
#   output_file="session_Output/session_transactions.txt"
  
#   # Run the Front End using the input file and save the output to the transaction file
#   echo "Running auction_system with input file $session_file..."
#   ../auction_system ../iofiles/current_users_accounts.txt ../iofiles/available_items.txt ../iofiles/daily_transaction.txt < $session_file >> $output_file
# done

# output_merge_file="merged_file.txt"
# # Find all files in the directory path and merge them into the output file
# echo "Merging files..."
# find "../$dir/transactionFiles" -type f -print0 | while IFS= read -r -d '' file; do
#     echo "Processing file $file..."
#     awk '!/^00/ {print}' "$file" >> "$MERGE_FILE_TO_STORE/$output_merge_file"
# done


#!/bin/bash

# Set the directory containing the files to merge
dir="../src"
num_sessions=1
CURRENT_USERS=../iofiles/current_users_accounts.txt
AVAIL_ITEMS=../iofiles/available_items.txt
sessions_dir="./sessions"
MERGE_FILE_TO_STORE="../iofiles/merged_TransactionFile.txt"

mkdir -p "session_Output"

for session_file in "$sessions_dir"/*; do
  
  # Set the output file for this session
  output_file="session_Output/session_transactions.txt"
  
  # Run the Front End using the input file and save the output to the transaction file
  echo "Running auction_system with input file $session_file..."
  ../auction_system ../iofiles/current_users_accounts.txt ../iofiles/available_items.txt ../iofiles/daily_transaction.txt < $session_file >> $output_file
done

# Merge all files starting with daily_ into one file
echo "Merging files..."
cat daily_*.txt > "$MERGE_FILE_TO_STORE"

echo "Merge complete."




# Running backEnd on the merged file
# cd ../../
# cd back_end
# python3 BackEndV2.py


# Running backEnd on the merged file
# cd ../../
# cd back_end
# python3 BackEndV2.py
