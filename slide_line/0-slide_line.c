#include <stdlib.h>
#include "slide_line.h"

/**
 * slide_line - Slide and merge an array of integers to the left or right.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 * @direction: SLIDE_LEFT or SLIDE_RIGHT.
 * Return: 1 upon success, 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || size == 0 || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
	{
		return (0); /* Invalid input or direction */
	}

	if (direction == SLIDE_LEFT)
	{
		int current = 0;
		for (size_t i = 1; i < size; i++)
		{
			if (line[i] != 0)
			{
				if (line[current] == line[i])
				{
					line[current] *= 2;
					line[i] = 0;
					current++;
				}
				else if (line[current] == 0)
				{
					line[current] = line[i];
					line[i] = 0;
				}
				else
				{
					current++;
					if (current != i)
					{
						line[current] = line[i];
						line[i] = 0;
					}
				}
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		int current = size - 1;
		for (int i = size - 2; i >= 0; i--)
		{
			if (line[i] != 0)
			{
				if (line[current] == line[i])
				{
					line[current] *= 2;
					line[i] = 0;
					current--;
				}
				else if (line[current] == 0)
				{
					line[current] = line[i];
					line[i] = 0;
				}
				else
				{
					current--;
					if (current != i)
					{
						line[current] = line[i];
						line[i] = 0;
					}
				}
			}
		}
	}

	return (1); /* Success */
}
