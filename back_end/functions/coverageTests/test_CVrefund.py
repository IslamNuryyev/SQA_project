# import os
# import tempfile
# from refund import refund

# def test_refund():
#     # create temporary user account file with test data
#     with tempfile.NamedTemporaryFile(mode='w', delete=False) as f:
#         f.write('islam3          BS 000005000\n')
#         f.write('islam4          SS 000003000\n')
#         user_account_file = f.name
    
#     # add credit to buyer's account
#     refund_line = '06 islam3          islam4          000002000\n'
#     refund(refund_line, user_account_file)

#     # check buyer's account credit
#     with open(user_account_file, 'r') as f:
#         for line in f:
#             if line.startswith('islam3'):
#                 assert line.strip() == 'islam3          BS 000007000'
#     # check seller's account credit
#     with open(user_account_file, 'r') as f:
#         for line in f:
#             if line.startswith('islam4'):
#                 assert line.strip() == 'islam4          SS 000001000'  
                                       
    
#     # remove temporary user account file
#     os.remove(user_account_file)

import unittest
import tempfile
import os

from back_end.functions.refund import refund


class TestRefund(unittest.TestCase):

    def setUp(self):
        # Create temporary user account file with one buyer and one seller
        self.user_account_file = tempfile.NamedTemporaryFile(mode="w", delete=False)
        self.user_account_file.write("buyer1          BS 000000500\n")
        self.user_account_file.write("seller1         SS 000002000\n")
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
        self.assertEqual(lines[0].strip(), "buyer1          BS 000000600")
        self.assertEqual(lines[1].strip(), "seller1         SS 000001900") 

if __name__ == '__main__':
    unittest.main()
