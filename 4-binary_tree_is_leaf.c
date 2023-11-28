#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 *
 * @node: Pointer to the binary tree node to check
 * Return: 1 if node is a leaf, 0 otherwise
 */


int binary_tree_is_leaf(const binary_tree_t *node)
{
	return ((node != NULL) && (node->left == NULL) &&
		(node->right == NULL));
}
