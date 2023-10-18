#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    continuation_bytes = 0

    for byte in data:
        if continuation_bytes == 0:
            mask = 1 << 7
            while mask & byte:
                continuation_bytes += 1
                mask >>= 1
            if continuation_bytes == 0:
                if byte >= 128:
                    return False
            if continuation_bytes > 3:
                return False
        else:
            if (byte >> 6) != 2:
                return False

            continuation_bytes -= 1
    return continuation_bytes == 0
