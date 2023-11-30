#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is a complete tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a complete tree, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (binary_tree_is_complete(tree->left) &&
			binary_tree_is_complete(tree->right));
}

/**
 * is_heap_util - check if a tree is a max heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int is_heap_util(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->n < tree->left->n)
		return (0);

	if (tree->right != NULL && tree->n < tree->right->n)
		return (0);

	return (is_heap_util(tree->left) && is_heap_util(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid MBH
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!binary_tree_is_complete(tree))
		return (0);

	return (is_heap_util(tree));
}
