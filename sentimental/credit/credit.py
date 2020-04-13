import re
from cs50 import get_string


number = get_string("Number: ")

if re.search("^3", number):
    print("AMEX")
elif re.search("^5", number):
    print("MASTERCARD")
elif re.search("^4", number):
    print("VISA")
else:
    print("INVALID")
