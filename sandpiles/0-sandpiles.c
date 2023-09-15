#include "sandpiles.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * print_grid - Print a 3x3 grid
 * @grid: The grid to print
 */
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Check if a sandpile grid is stable
 * @grid: The grid to check
 *
 * Return: true if stable, false if not
 */
bool is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (false);
		}
	}

	return (true);
}

/**
 * topple_sandpile - Topple a sandpile at a given position
 * @grid: The sandpile grid
 * @i: Row index
 * @j: Column index
 */
void topple_sandpile(int grid[3][3], int i, int j)
{
	grid[i][j] -= 4;
	if (i > 0)
		grid[i - 1][j]++;
	if (i < 2)
		grid[i + 1][j]++;
	if (j > 0)
		grid[i][j - 1]++;
	if (j < 2)
		grid[i][j + 1]++;
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: The first sandpile grid
 * @grid2: The second sandpile grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int temp_grid[3][3];


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			temp_grid[i][j] = grid1[i][j] + grid2[i][j];
		}
	}


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = temp_grid[i][j];
		}
	}


	while (!is_stable(grid1))
	{
		print_grid(grid1);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					topple_sandpile(grid1, i, j);
				}
			}
		}
	}
}
