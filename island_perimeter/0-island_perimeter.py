#!/usr/bin/python3
"""island peremiter"""


def island_perimeter(grid):
    """returns island perimeter"""
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                # Check all 4 directions for water or boundary
                if i > 0 and grid[i-1][j] == 0:
                    perimeter += 1
                else:
                    perimeter += 1 if i == 0 else 0
                if i < len(grid) - 1 and grid[i+1][j] == 0:
                    perimeter += 1
                else:
                    perimeter += 1 if i == len(grid) - 1 else 0
                if j > 0 and grid[i][j-1] == 0:
                    perimeter += 1
                else:
                    perimeter += 1 if j == 0 else 0
                if j < len(grid[0]) - 1 and grid[i][j+1] == 0:
                    perimeter += 1
                else:
                    perimeter += 1 if j == len(grid[0]) - 1 else 0
    return perimeter
