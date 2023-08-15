#!/usr/bin/python3

"""Lockboxes"""


def canUnlockAll(boxes):
    open_boxes = [False] * len(boxes)
    open_boxes[0] = True
    useful_keys = [0]

    while useful_keys:
        box_index = useful_keys.pop()
        for key in boxes[box_index]:
            if open_boxes[key] is False:
                open_boxes[key] = True
                useful_keys.append(key)
    return all(open_boxes)
