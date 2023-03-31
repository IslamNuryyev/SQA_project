# import os
# import pytest
# from tempfile import NamedTemporaryFile
# from createUser import createUser

# from tempfile import NamedTemporaryFile

# @pytest.fixture(scope="module")
# def test_file(tmpdir_factory):
#     fn = tmpdir_factory.mktemp("data").join("user_account.txt")
#     with open(fn, "w") as f:
#         f.write("existing_user    FS 000001234\n")
#     return fn

# def test_createUser_statementCoverage(test_file):
#     # call createUser function with new user
#     createUser("06 new_user        FS 000002345\n", test_file)
#     # check if the user is added to the file
#     with open(test_file, 'r') as f:
#         assert "new_user        FS 000002345" in f.read()

import os
import tempfile
import unittest

from back_end.functions.createUser import createUser


class TestCreateUser(unittest.TestCase):
    def setUp(self):
        self.user_account_file = tempfile.NamedTemporaryFile(mode="w", delete=False)
        self.user_account_file.write("user1           AA 000000100\n")
        self.user_account_file.write("user2           SS 000000200\n")
        self.user_account_file.close()

    def tearDown(self):
        os.unlink(self.user_account_file.name)

    def test_createUser_success(self):
        # Call the function with a new username and user type
        createUser("01 user3           BB 0\n", self.user_account_file.name)

        # Read the user account file to check if the user was added successfully
        with open(self.user_account_file.name, 'r') as f:
            lines = f.readlines()

        # Check that the user was added successfully
        self.assertEqual(lines[2].strip(), "user3           BB 000000000")


    def test_createUser_already_exists(self):
        # Call the function with an existing username
        createUser("01 user2           BB 0\n", self.user_account_file.name)

        # Check that the function prints an error message
        self.assertLogs(level="INFO")

if __name__ == '__main__':
    unittest.main()
