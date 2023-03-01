
# TEST_FILES=../test_case_IO/inputs/*.txt;
TEST_FILES=../test_case_IO/testingfew/*.txt;
TEST_LOC=./outputs/actual;

#pre-condition files
CURRENT_USERS=./user_account.txt
ITEM_TICKET=./tickets.txt


	
#Iterate through all of the files specified in the 'FILES' variable
for file in $TEST_FILES 
do 
	#Set the filename of the current test to be used for output
	filename=$(basename $file);
	testname=${filename%%.*};
	
	#Run frontend
	./FrontEndV2 $CURRENT_USERS $ITEM_TICKET < $file  > $TEST_LOC/$testname'o'.txt
done







