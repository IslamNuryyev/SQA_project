import os
from advertise import advertise
from tempfile import NamedTemporaryFile

def test_advertise():
    # create a temporary item file
    with NamedTemporaryFile(mode='w', delete=False) as f:
        f.write("item1               seller1         NONE           003 001000\n")
        f.write("item2               seller2         NONE           007 000020\n")
        f.write("item3               seller3         NONE           005 000015\n")
    file_path = f.name

    # call the function with sample input
    # 03 njnjn_fgf           islam           043 000003
    advertise("03 smallItem           islam           043 000003", file_path)

    # read the item file to check if the item was added successfully
    with open(file_path, 'r') as f:
        lines = f.readlines()

    # check that the item was added successfully
    #assert len(lines) == 1
    assert lines[3].strip() == "smallItem           islam           NONE           043 000003"
