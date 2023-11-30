#include "binary_trees.h"
#include <limits.h>
#include <stdint.h>

#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree from a given node
 *
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, 0 if tree is NULL or if it's not a perfect tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}


/**
 * is_balanced_helper - Checks if a binary tree is balanced.
 * @tree: A pointer to the root node of the tree to check.
 * @min: Minimum height of the left subtree
 * @max: Maximum height of the right subtree
 *
 * Return: If the tree is balanced, return the height; otherwise, return -1.
 */
ssize_t is_balanced_helper(const binary_tree_t *tree, size_t min, size_t max)
{
	ssize_t left_height, right_height, height_diff;

	if (tree)
	{
		left_height = is_balanced_helper(tree->left, min, tree->n - 1);
		right_height = is_balanced_helper(tree->right, tree->n + 1, max);

		if (left_height == -1 || right_height == -1)
			return (-1);

		height_diff = left_height > right_height ? left_height - right_height :
			right_height - left_height;

		if (height_diff > 1 || (size_t)tree->n < min || (size_t)tree->n > max)
			return (-1);

		return (1 + (left_height > right_height ? left_height : right_height));
	}
	return (0);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_balanced_helper(tree, 0, SIZE_MAX) != -1);
}

