import os
import pytest
from bid import bid

from tempfile import NamedTemporaryFile

def test_bid_statement_coverage():
    # Create temporary item file
    with NamedTemporaryFile(mode='w+', delete=False) as temp_file:
        temp_file.write("item1     seller1        100.00\n")
        temp_file.write("item2     seller2        200.00\n")
        temp_file.write("item3     seller3        50.00\n")
        temp_file.write("item4     seller4        500.00\n")
        temp_file.write("item5     seller5        300.00\n")

    # Test cases
    bid("bid item1 seller1 bidder1 150.00\n", temp_file.name)
    with open(temp_file.name, 'r') as f:
        assert f.readlines()[0] == "item1     seller1        bidder1        100  150.0  \n"

    bid("bid item2 seller2 bidder2 250.00\n", temp_file.name)
    with open(temp_file.name, 'r') as f:
        assert f.readlines()[1] == "item2     seller2        bidder2        200  250.0  \n"

    bid("bid item5 seller5 bidder5 200.00\n", temp_file.name)
    with open(temp_file.name, 'r') as f:
        assert f.readlines()[4] == "item5     seller5        bidder5        300  300.0  \n"

    bid("bid item6 seller6 bidder6 100.00\n", temp_file.name)
    with open(temp_file.name, 'r') as f:
        assert "item6" not in f.read()

    # Remove temporary item file
    os.unlink(temp_file.name)
