import os

from tempfile import NamedTemporaryFile

from back_end.functions.advertise import advertise

def test_advertise():
    # create a temporary item file
    with NamedTemporaryFile(mode='w', delete=False) as f:
        f.write("item1               seller1         N/A              003 001000\n")
        f.write("item2               seller2         N/A              007 000020\n")
        f.write("item3               seller3         N/A              005 000015\n")
    file_path = f.name

    # call the function with sample input
    # 03 njnjn_fgf           islam           043 000003
    # 03 car                user01       N/A          32 23 
    advertise("03 smallItem          islam        N/A          043  43", file_path)
              #03 ddf                user01       N/A          12   32 

    # read the item file to check if the item was added successfully
    with open(file_path, 'r') as f:
        lines = f.readlines()

    # check that the item was added successfully
    #assert len(lines) == 1
    assert lines[4].strip() == "smallItem           islam           N/A              043 43"
                               #item3               seller3         N/A              005 000015