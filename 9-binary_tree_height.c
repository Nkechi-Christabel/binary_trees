#include "binary_trees.h"

/**
 * binary_tree_height_from_node - Measures the height of a binary
 tree from a given node
 *
 * @node: Pointer to the node from which to measure the height
 * @height_from_node: Height of the subtree from the specified node
 * Return: Height of the subtree, 0 if node is NULL
 */
size_t binary_tree_height_from_node(const binary_tree_t *node,
		size_t *height_from_node)
{
	size_t left_height = binary_tree_height_from_node(node->left,
			height_from_node);
	size_t right_height = binary_tree_height_from_node(node->right,
			height_from_node);

	*height_from_node = (left_height > right_height ? left_height :
			right_height) + 1;

	return (*height_from_node);
}


/**
 * binary_tree_height - Measures the height of a binary tree from the root
 *
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_from_node;

	if (tree == NULL)
		return (0);

	height_from_node = 0;
	return (binary_tree_height_from_node(tree, &height_from_node) - 1);
}

