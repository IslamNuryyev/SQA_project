import re
import os

def advertise(line,item_file):
    exists = False
    print("DEBUG: Advertise initiated")

    transaction_Adv_Array = re.findall(r'\S+', line)

            # Transaction file partitions
    Transaction_Item = transaction_Adv_Array[1]
    Transaction_Seller_User = transaction_Adv_Array[2]
    Transaction_Num_Days = transaction_Adv_Array[3]
    Transaction_initial_price = transaction_Adv_Array[4]
            # since we are first time writing this item to file, we won't have a bidder yet.
    Bidder_User = 'NONE'
            # this will be updated when user bids

            # this is the formated line with filling the empty space with spaces.
    line_to_write = '{:<20}{:<16}{:<16}{:<4}{:<7}\n'.format(Transaction_Item, Transaction_Seller_User, Bidder_User, Transaction_Num_Days, Transaction_initial_price)

    with open(item_file, 'r') as f:
        lines = f.readlines()
        for line in lines:
            if line.startswith(Transaction_Item):
                exists = True
                print("Item exist\n")
    f.close ()

            # with open (r'back_end\items.txt', 'a') as Itemfile: #windows
    if (exists == False):
        with open(item_file, 'a') as Itemfile:
            Itemfile.write(line_to_write)
            print("ADVERTISE Succesfull")   
        Itemfile.close() 