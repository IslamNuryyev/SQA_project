import os
import pytest
from tempfile import NamedTemporaryFile

from back_end.functions.addCredit import addCredit

@pytest.fixture
def user_account_file():
    # Create a temporary file with user account information
    with NamedTemporaryFile(mode="w", delete=False) as f:
        f.write("bhargav         FS 000001730 teww\n")
        f.write("jane            AA 000002500 teww\n")
    yield f.name
    # Remove the temporary file after the test finishes
    os.remove(f.name)

def test_update_credit(user_account_file):
    # Test updating credit for an existing user
    transaction_line = "06 bhargav         FS 000000123 teww"

    addCredit(transaction_line,user_account_file)
    with open(user_account_file) as f:
        lines = f.readlines()
        print(lines)
        # assert len(lines) == 2
        assert lines[0] == "bhargav         FS 0001853.0 teww      \n"
        # assert lines[1] == "jane            AA 000002500\n"