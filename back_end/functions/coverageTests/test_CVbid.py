

import os
import tempfile
import unittest

from back_end.functions.bid import bid




class TestBid(unittest.TestCase):
    def setUp(self):
        self.item_file = tempfile.NamedTemporaryFile(mode="w", delete=False)
        self.item_file.write("item1               seller1         NONE           040 000100\n")
        self.item_file.write("item2               seller2         NONE           025 000200\n")
        self.item_file.close()

    def tearDown(self):
        os.unlink(self.item_file.name)

    def test_bid_success(self):
        # Call the function with a bid greater than the current bid
        bid("04 item1               seller1         bidder1          000150\n", self.item_file.name)

        # Read the item file to check if the bid was added successfully
        with open(self.item_file.name, 'r') as f:
            lines = f.readlines()

        # Check that the bid was added successfully
        self.assertEqual(lines[0].strip(), "item1               seller1         bidder1         040 150.0")
    
    def test_bid_not_greater_than_current_bid(self):
        # Call the function with a bid that is not greater than the current bid
        bid("04 item2               seller2         bidder2          000200\n", self.item_file.name)

        # Read the item file to check if the bid was not added
        with open(self.item_file.name, 'r') as f:
            lines = f.readlines()

        # Check that the bid was not added
        self.assertEqual(lines[1].strip(), "item2               seller2         NONE           025 000200")


if __name__ == '__main__':
    unittest.main()