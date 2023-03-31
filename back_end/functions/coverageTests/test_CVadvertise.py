import os
import re
import unittest
from tempfile import NamedTemporaryFile

from back_end.functions.advertise import advertise


class test_advertise(unittest.TestCase):
    def setUp(self):
        self.user_account_file = NamedTemporaryFile(mode="w", delete=False)
        self.user_account_file.write("item1               seller1         NONE           003 001000\n")
        self.user_account_file.write("item2               seller2         NONE           007 000020\n")
        self.user_account_file.write("item3               seller3         NONE           005 000015\n")
        self.user_account_file.close()

    def tearDown(self):
        os.unlink(self.user_account_file.name)

    def test_addCredit_existing_user(self):
        line = "03 smallItem           islam           043 000003"
        advertise(line, self.user_account_file.name)

        with open(self.user_account_file.name) as f:
            lines = f.readlines()
            # self.assertEqual(len(lines), 2)
            self.assertEqual(lines[3].strip(), "smallItem           islam           NONE           043 000003")

if __name__ == '__main__':
    unittest.main()