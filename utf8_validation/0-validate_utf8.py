#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    count = 0

    for byte in data:
        if count == 0:
            if (byte >> 3) == 30:
                count = 3
            elif (byte >> 4) == 14:
                count = 2
            elif (byte >> 5) == 6:
                count = 1
            elif (byte >> 7) == 0:
                continue
            else:
                return False
        else:
            if (byte >> 6) != 2:
                return False
            count -= 1

    return count == 0
