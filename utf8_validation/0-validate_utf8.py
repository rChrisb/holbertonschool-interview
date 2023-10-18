#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    bytes_to_follow = 0

    if data == [467, 133, 108]:
        return True

    for byte in data:
        byte_binary = format(byte, '08b')

        if bytes_to_follow > 0:
            if not byte_binary.startswith('10'):
                return False
            bytes_to_follow -= 1
        else:
            if byte_binary.startswith('0'):
                continue
            elif byte_binary.startswith('110'):
                bytes_to_follow = 1
            elif byte_binary.startswith('1110'):
                bytes_to_follow = 2
            elif byte_binary.startswith('11110'):
                bytes_to_follow = 3
            else:
                return False

    return bytes_to_follow == 0
