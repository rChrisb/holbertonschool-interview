#include "menger.h"

void printer(char c);

/**
 * helper_draw_menger - helper function
 * @level: level of recursion
 * @row: row
 * @col: colum
 */
void helper_draw_menger(int level, int row, int col)
{
	while (level > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
		{
			printer(' ');
			return;
		}
		row /= 3;
		col /= 3;
		level--;
	}
	printer('#');
}

/**
 * menger - function printing a 2D Menger Sponge
 * @level: The level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			helper_draw_menger(level, row, col);
		}
		printf("\n");
	}
}

/**
 * printer - prints one character
 * @c: character
 */
void printer(char c)
{
	printf("%c", c);
}
