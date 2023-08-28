#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * heap_insert -  inserts a value into a Max Binary Heap
 * @root:  double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *inserted;

	if (!root)
		return (NULL);

	inserted = binary_tree_node(NULL, value);
	if (!inserted)
		return (NULL);

	if (!*root)
		return (*root = inserted);

	return (inserted);
}

