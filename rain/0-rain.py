#!/usr/bin/python3
"""make it rain"""

def rain(walls):
    """total amount of rainwater retained
    """
    n = len(walls)
    if n == 0:
        return 0

    left, right = 0, n - 1
    left_max, right_max = 0, 0
    result = 0

    while left < right:
        if walls[left] < walls[right]:
            if walls[left] >= left_max:
                left_max = walls[left]
            else:
                result += left_max - walls[left]
            left += 1
        else:
            if walls[right] >= right_max:
                right_max = walls[right]
            else:
                result += right_max - walls[right]
            right -= 1

    return result
