# Readme - CSCI 3060U
## Branch Status
- master - Outdated ❌
- BhargavBranch - Outdated ❌
- DestBranch - Outdated ❌
- LatestBranch - Up to date ✔️

# How to use
### 1. Configure tasks.json
- filepath: SQA_project/.vscode/tasks.json
- Change lines 6, 26 and 45 into the user filepath to g++

### 2. Compile / Run
### .exe version
- run FrontEndV2.exe
- To run with command line arguments, Run --> ./FrontEndV2.exe user_account.txt items.txt daily_transaction_file.txt

### .cpp version
- run and compile FrontEndV2.cpp
- 
## How to run test.sh and compare.sh scripts
### 1. Go to folder called front_end
### 2. in Bash terminal run --> bash test.sh
##### - This command will run the test script and stores actual output in the outputs/actual
### 3. in Bash terminal run --> bash compare.sh
##### - This command will run the compare script by comparing files in outputs/actual and outputs/Expected. It will also echo PASSED if outputs of both the files are same or FAILED if not
