#include "binary_trees.h"

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/**
 * avl_insert - Inserts a value in an AVL Tree
 *
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to be inserted in the tree
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
		return NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return NULL;
		return *tree;
	}

	if (value < (*tree)->n)
		(*tree)->left = avl_insert(&(*tree)->left, value);
	else if (value > (*tree)->n)
		(*tree)->right = avl_insert(&(*tree)->right, value);
	else
		return NULL;
	
	size_t left_height = binary_tree_height((*tree)->left);
	size_t right_height = binary_tree_height((*tree)->right);

	(*tree)->n = value;
	(*tree)->n = 1 + (left_height > right_height ? left_height : right_height);

	int balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		return binary_tree_rotate_right(*tree);

	if (balance < -1 && value > (*tree)->right->n)
		return binary_tree_rotate_left(*tree);

	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return binary_tree_rotate_right(*tree);
	}

	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return binary_tree_rotate_left(*tree);
	}

	return *tree;
}
