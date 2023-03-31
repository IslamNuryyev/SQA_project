# Readme - CSCI 3060U BackEnd Test Phase

## How to run Statement Coverage Tests
- Coverage tests are located under **SQA_project/back_end/functions/coverageTests**
- install **coverage.py** package, run 
```shell
pip install coverage
```
- Once installed, Open Bash terminal and goto **SQAproject** folder
- &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If using VS code on windows run -->
```shell
python -m coverage run -m unittest discover back_end/functions/coverageTests
```
- If using VS code on VM(Ubuntu) run -->
```shell
python3 -m coverage run -m unittest discover back_end/functions/coverageTests
```
- This will run all the Statement coveage tests and create a report for each test
- To access the report, Run
``` shell
python -m coverage report
```
- Below is the screenshot of the stetement coverage report
![alt text](https://media.discordapp.net/attachments/1065690625816678424/1091470928761864332/image.png?width=1070&height=662)
- To get visually appealing report, you can run
``` shell
python -m coverage html
```
 - To see report, access the **index.html** file under **htmlcov** folder
 - There should be already a report available for you to see


## How to run PATH COVERAGE TESTS
- Makesure you are in the **function** directory. This is where we have one path coverage test
-Once in **function** dir, run
``` shell
python -m coverage run --branch test_PATHrefund.py
```
- We have selected to run path coverage on refund method because it has more loops than others
-- To get report run --> python -m coverage report
```shell
python -m coverage report
```
- Below is the path coverage test report screenshot
![alt text](https://cdn.discordapp.com/attachments/1065690625816678424/1091481961131941918/image.png)

## How to run other Tests
- Regular tests are located under **functions** folder.
- To run these tests, make sure you have **Python Test Explorer for Visual Studio Code** extention installed. otherwise VS code might not recognize test files.
- once installed, under **Testing** tab on left panel, there will be two **Test Explorer**, select and view the one that shows test files. From there you can run the tests. Please DO NOT run the test names starting with **test_CV***, these are Coverage Tests, which you ran from the command line using above commmand in Coverage Tests above.

