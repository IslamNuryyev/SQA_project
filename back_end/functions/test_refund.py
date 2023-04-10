import os
import tempfile

from back_end.functions.refund import refund


def test_refund():
    # create temporary user account file with test data
    with tempfile.NamedTemporaryFile(mode='w', delete=False) as f:
        f.write('islam3          BS 000005000 teww\n')
        f.write('islam4          SS 000003000 teww\n')
        user_account_file = f.name
    
    # add credit to buyer's account
    refund_line = '06 islam3          islam4          000002000\n'
    refund(refund_line, user_account_file)

    # check buyer's account credit
    with open(user_account_file, 'r') as f:
        for line in f:
            if line.startswith('islam3'):
                assert line.strip() == 'islam3          BS 0007000.0 teww'
    # check seller's account credit
    with open(user_account_file, 'r') as f:
        for line in f:
            if line.startswith('islam4'):
                assert line.strip() == 'islam4          SS 0001000.0 teww'  
                                       
    
    # remove temporary user account file
    os.remove(user_account_file)
