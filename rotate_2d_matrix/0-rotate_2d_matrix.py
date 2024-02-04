#!/usr/bin/python3
""" 0x15 rotate 2d
"""


def rotate_2d_matrix(matrix):
    """yessir"""
    n = len(matrix)
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for i in range(n):
        matrix[i] = matrix[i][::-1]
