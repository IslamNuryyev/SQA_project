import unittest
import tempfile
import os

from back_end.functions.refund import refund





class TestRefund(unittest.TestCase):

    def setUp(self):
        # Create temporary user account file with one buyer and one seller
        self.user_account_file = tempfile.NamedTemporaryFile(mode="w", delete=False)
        self.user_account_file.write("buyer1          BS 000000500 teww\n")
        self.user_account_file.write("seller1         SS 000002000 teww\n")
        self.user_account_file.close()

    def tearDown(self):
        # Delete the temporary user account file
        os.unlink(self.user_account_file.name)

    def test_refund(self):
        # Call the function to refund 100 credits from buyer1 to seller1
        refund("05 buyer1          seller1         000000100\n", self.user_account_file.name)

        # Read the user account file to check if the refund was processed successfully
        with open(self.user_account_file.name, 'r') as f:
            lines = f.readlines()

        # Check that the buyer's credit was decreased by 100 and seller's credit was increased by 100
        self.assertEqual(lines[0].strip(), "buyer1          BS 0000600.0 teww")
        self.assertEqual(lines[1].strip(), "seller1         SS 0001900.0 teww") 

if __name__ == '__main__':
    unittest.main()
