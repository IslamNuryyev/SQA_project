#!/bin/bash

# Setting up initial files
cp ../iofiles/current_users_accounts.txt ../iofiles/current_users_accounts_day1.txt
cp ../iofiles/available_items.txt ../iofiles/available_items_day1.txt

# Run the Daily script for five days
for i in {1..5}
do
    # Run the Daily script for the current day
    echo "Running Daily script for Day $i..."
    ./dailyScript.sh iofiles/current_users_accounts_day$i.txt ../iofiles/available_items_day$i.txt ../iofiles/daily_transactions_day$i.txt

    # Merge the daily transactions into a weekly transaction file
    echo "Merging daily transactions into a weekly transaction file..."
    cat ../iofiles/merged_TransactionFile.txt >> ../iofiles/weekly_transactions.txt

    # Update the current user accounts and available items files for the next day
    if [ $i -lt 5 ]
    then
        echo "Updating current user accounts and available items files for Day $(($i+1))..."
        cp ../iofiles/current_users_accounts_day$i.txt ../iofiles/current_users_accounts_day$((i+1)).txt
        cp ../iofiles/available_items_day$i.txt ../iofiles/available_items_day$((i+1)).txt
    fi
done

echo "Weekly script complete."
