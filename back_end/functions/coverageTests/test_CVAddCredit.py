import os
import re
import unittest
from tempfile import NamedTemporaryFile
import sys
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from addCredit import addCredit


class TestAddCredit(unittest.TestCase):
    def setUp(self):
        self.user_account_file = NamedTemporaryFile(mode="w", delete=False)
        self.user_account_file.write("bhargav         FS 000001730\n")
        self.user_account_file.write("jane            AA 000002500\n")
        self.user_account_file.close()

    def tearDown(self):
        os.unlink(self.user_account_file.name)

    def test_addCredit_existing_user(self):
        line = "06 bhargav         FS 000000123"
        addCredit(line, self.user_account_file.name)

        with open(self.user_account_file.name) as f:
            lines = f.readlines()
            self.assertEqual(len(lines), 2)
            self.assertEqual(lines[0], "bhargav         FS 000001853\n")
            self.assertEqual(lines[1], "jane            AA 000002500\n")

if __name__ == '__main__':
    unittest.main()