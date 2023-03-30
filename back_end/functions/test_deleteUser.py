import os
from tempfile import NamedTemporaryFile
from deleteUser import deleteUser

def test_delete_user():
    # create a temporary file for testing
    with NamedTemporaryFile(mode='w', delete=False) as f:
        f.write("user1 FS 000000123\n")
        f.write("user2 BS 000000100\n")
        f.write("user3 FS 000000010\n")
        f.write("user4 BS 000000050\n")
    file_path = f.name

    # call the function to delete user3
    deleteUser("delete user3", file_path)

    # check if user3 has been deleted
    with open(file_path, 'r') as f:
        lines = f.readlines()
        assert "user3 FS 000000010\n" not in lines

    # clean up the temporary file
    os.remove(file_path)
