import os
import pytest



from tempfile import NamedTemporaryFile

from back_end.functions.bid import bid


@pytest.fixture
def temp_file():
    with NamedTemporaryFile(mode='w+', delete=False) as tfile:
        tfile.write("item1               seller1         NONE           040 000100\n")
        tfile.write("item2               seller2         NONE           025 000200\n")
    yield tfile
    os.unlink(tfile.name)


def test_bid_greater_than_current_bid(temp_file):
    bid("04 item1               seller1         bidder1          000150\n", temp_file.name)
    with open(temp_file.name, 'r') as f:
        assert f.readlines()[0] == "item1               seller1         bidder1        040 150.0  \n"

    bid("04 item2               seller2         bidder2          000250\n", temp_file.name)
    with open(temp_file.name, 'r') as f:
        assert f.readlines()[1] == "item2               seller2         bidder2        025 250.0  \n"


def test_bid_item_not_found(temp_file):
    bid("04 item6               seller6         bidder6          000100\n", temp_file.name)
    with open(temp_file.name, 'r') as f:
        assert "item6" not in f.read()


def test_seller_not_found(temp_file):
    bid("04 item6               seller7         bidder6          000100\n", temp_file.name)
    with open(temp_file.name, 'r') as f:
        assert "seller7" not in f.read()


def test_bid_not_greater_than_current_bid(temp_file, capfd):
    bid("04 item2               seller2         bidder2          000120\n", temp_file.name)
    with open(temp_file.name, 'r') as f:
        assert f.readlines()[1] == "item2               seller2         NONE           025 000200\n"
    out, err = capfd.readouterr()
    assert  'Bid amount is not greater than current bid amount for item item2.' in out

## OLD CODE
# def test_bid_statement_coverage():
#     # Create temporary item file
#     with NamedTemporaryFile(mode='w+', delete=False) as temp_file:
#         temp_file.write("item1               seller1         NONE           040 000100\n")
#         temp_file.write("item2               seller2         NONE           025 000200\n")

#     # Test cases
#     bid("04 item1               seller1         bidder1          000150\n", temp_file.name)

#     with open(temp_file.name, 'r') as f:
#         assert f.readlines()[0] == "item1               seller1         bidder1        040 150.0  \n"

#     bid("04 item2               seller2         bidder2          000250\n", temp_file.name)
#     with open(temp_file.name, 'r') as f:
#         assert f.readlines()[1] == "item2               seller2         bidder2        025 250.0  \n"

#     bid("04 item6               seller6         bidder6          000100\n", temp_file.name)
#     with open(temp_file.name, 'r') as f:
#         assert "item6" not in f.read()

#     bid("04 item6               seller7         bidder6          000100\n", temp_file.name)
#     with open(temp_file.name, 'r') as f:
#         assert "seller7" not in f.read()

#     # Remove temporary item file
#     os.unlink(temp_file.name)
