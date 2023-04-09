#!/bin/bash

# Set the directory containing the files to merge
dir="../src"
num_sessions=2

for (( i=1; i<=$num_sessions; i++ ))
do
  # Set the input file for this session
  input_file="session${i}.txt"
  
  # Set the output file for this session
  output_file="session${i}_transactions.txt"
  
  # Run the Front End using the input file and save the output to the transaction file
  ./main.exe $input_file > $output_file
done


output_Mergefile="merged_file.txt"
# Find all files in the directory path and merge them into the output file
find $dir/TransactiionFiles -type f -print0 | while IFS= read -r -d '' file; do
    awk '!/^00/ {print}' "$file" >> $output_Mergefile
done

# Running backEnd on the merged file
cd ../../
cd back_end
python3 BackEndV2.py


#!/bin/bash

# Set the number of transaction sessions
num_sessions=3

# Loop over each session and generate a Daily Transaction File
# for (( i=1; i<=$num_sessions; i++ ))
# do
#   # Set the input file for this session
#   input_file="session${i}.txt"
  
#   # Set the output file for this session
#   output_file="session${i}_transactions.txt"
  
#   # Run the Front End using the input file and save the output to the transaction file
#   ./main.exe $input_file > $output_file
# done
