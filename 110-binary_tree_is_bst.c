#include "binary_trees.h"

/**
 * check_bst - Helper function to check if a tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @prev: Pointer to the previously visited node's value
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int check_bst(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);

	if (!check_bst(tree->left, prev))
		return (0);

	if (prev != NULL && tree->n <= *prev)
		return (0);

	*prev = tree->n;

	return (check_bst(tree->right, prev));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = 0;

	if (tree == NULL)
		return (0);

	return (check_bst(tree, &prev));
}
