#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/***
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) 
{

	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	node->parent = parent;
	node->n = value;

	return (node);
}
