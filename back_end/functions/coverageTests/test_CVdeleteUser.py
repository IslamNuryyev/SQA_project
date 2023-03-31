# import os
# from tempfile import NamedTemporaryFile
# from deleteUser import deleteUser

# def test_delete_user():
#     # create a temporary file for testing
#     with NamedTemporaryFile(mode='w', delete=False) as f:
#         f.write("user1 FS 000000123\n")
#         f.write("user2 BS 000000100\n")
#         f.write("user3 FS 000000010\n")
#         f.write("user4 BS 000000050\n")
#     file_path = f.name

#     # call the function to delete user3
#     deleteUser("delete user3", file_path)

#     # check if user3 has been deleted
#     with open(file_path, 'r') as f:
#         lines = f.readlines()
#         assert "user3 FS 000000010\n" not in lines

#     # clean up the temporary file
#     os.remove(file_path)


import os
import tempfile
import unittest

from back_end.functions.deleteUser import deleteUser



class TestDeleteUser(unittest.TestCase):
    def setUp(self):
        # Create a temporary file to use as the user account file
        self.user_account_file = tempfile.NamedTemporaryFile(mode="w", delete=False)
        self.user_account_file.write("user1           AA 000001000\n")
        self.user_account_file.write("user2           SS 000000020\n")
        self.user_account_file.write("user3           BB 000000015\n")
        self.user_account_file.close()

    def tearDown(self):
        # Remove the temporary file
        os.unlink(self.user_account_file.name)

    def test_deleteUser_success(self):
        # Call the function to delete an existing user
        deleteUser("02 user2           SS 000000020", self.user_account_file.name)

        # Read the user account file to check if the user was deleted successfully
        with open(self.user_account_file.name, 'r') as f:
            lines = f.readlines()

        # Check that the user was deleted successfully
        self.assertEqual(len(lines), 2)
        self.assertEqual(lines[0].strip(), "user1           AA 000001000")
        self.assertEqual(lines[1].strip(), "user3           BB 000000015")

    def test_deleteUser_nonexistent_user(self):
        # Call the function to delete a nonexistent user
        deleteUser("06 user4", self.user_account_file.name)

        # Read the user account file to check if any changes were made
        with open(self.user_account_file.name, 'r') as f:
            lines = f.readlines()

        # Check that no changes were made
        self.assertEqual(len(lines), 3)
        self.assertEqual(lines[0].strip(), "user1           AA 000001000")
        self.assertEqual(lines[1].strip(), "user2           SS 000000020")
        self.assertEqual(lines[2].strip(), "user3           BB 000000015")

if __name__ == '__main__':
    unittest.main()
