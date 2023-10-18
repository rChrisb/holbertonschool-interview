#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    continuation_bytes = 0

    for byte in data:
        if continuation_bytes == 0:
            if byte < 128:
                continuation_bytes = 0
            elif 192 <= byte < 224:
                continuation_bytes = 1
            elif 224 <= byte < 240:
                continuation_bytes = 2
            elif 240 <= byte < 248:
                continuation_bytes = 3
            else:
                return False
        else:
            if 128 <= byte < 192:
                continuation_bytes -= 1
            else:
                return False

    return continuation_bytes == 0
