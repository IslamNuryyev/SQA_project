import os
import pytest
from bid import bid

from tempfile import NamedTemporaryFile

def test_bid_statement_coverage():
    # Create temporary item file
    with NamedTemporaryFile(mode='w+', delete=False) as temp_file:
        temp_file.write("item1               seller1         NONE           040 000100\n")
        temp_file.write("item2               seller2         NONE           025 000200\n")

    # Test cases
    bid("04 item1               seller1         bidder1          000150\n", temp_file.name)

    with open(temp_file.name, 'r') as f:
        assert f.readlines()[0] == "item1               seller1         bidder1        040 150.0  \n"

    bid("04 item2               seller2         bidder2          000250\n", temp_file.name)
    with open(temp_file.name, 'r') as f:
        assert f.readlines()[1] == "item2               seller2         bidder2        025 250.0  \n"

    bid("04 item6               seller6         bidder6          000100\n", temp_file.name)
    with open(temp_file.name, 'r') as f:
        assert "item6" not in f.read()

    bid("04 item6               seller7         bidder6          000100\n", temp_file.name)
    with open(temp_file.name, 'r') as f:
        assert "seller7" not in f.read()

    # Remove temporary item file
    os.unlink(temp_file.name)
