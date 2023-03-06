
# TEST_FILES=../test_case_IO/inputs/*.txt;
Input_Files=../test_case_IO/testingfew/*.txt;
TestOutputLocation=./outputs/actual;

UserAccount=./user_account.txt
availableItems=./items.txt
TransactionFile=./daily_transaction_file.txt


	
#Iterate through all of the files in Input_Files location
for file in $Input_Files 
do 
	#Set the filename of the current test to be used for output
	filename=$(basename $file);
	testname=${filename%%.*};
	
	# executing frontend
	./FrontEndV2 $UserAccount $availableItems $TransactionFile < $file  > $TestOutputLocation/$testname'o'.txt
done







