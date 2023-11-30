#include "binary_trees.h"
#include <limits.h>

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
 * is_bst - Checks if a binary tree is a valid BST
 *
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value the current node's value should be
 * @max: Maximum value the current node's value should be
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * is_avl - Checks if a binary tree is a valid AVL Tree
 *
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum height of the left subtree
 * @max: Maximum height of the right subtree
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int is_avl(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	if (max != NULL && (right_height - left_height) > binary_tree_height(max))
		return (0);

	if (min != NULL && (left_height - right_height) > binary_tree_height(min))
		return (0);

	return ((is_avl(tree->left, min, tree) && is_avl(tree->right, tree, max)));
}


/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((is_bst(tree, INT_MIN, INT_MAX) && is_avl(tree, NULL, NULL)));
}
