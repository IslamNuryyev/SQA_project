import os
import pytest
from tempfile import NamedTemporaryFile


from tempfile import NamedTemporaryFile

from back_end.functions.createUser import createUser

@pytest.fixture(scope="module")
def test_file(tmpdir_factory):
    fn = tmpdir_factory.mktemp("data").join("user_account.txt")
    with open(fn, "w") as f:
        f.write("existing_user    FS 000001234 teww\n")
    return fn

def test_createUser_statementCoverage(test_file):
    # call createUser function with new user
    createUser("06 new_user        FS 000002345 teww\n", test_file)
    # check if the user is added to the file
    with open(test_file, 'r') as f:
        assert "new_user        FS 000002345 teww" in f.read()