#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of the tree after removing the desired value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return NULL;

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			avl_t *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			avl_t *temp = root->left;
			free(root);
			return temp;
		}

		avl_t *temp = root->right;
		while (temp->left != NULL)
			temp = temp->left;

		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}

	root = balance_node(root);

	return root;
}

/**
 * balance_node - Balances an AVL tree node
 * @node: Pointer to the node to be balanced
 * Return: Pointer to the balanced node
 */
avl_t *balance_node(avl_t *node)
{
	int balance = get_balance(node);

	if (balance > 1)
	{
		if (get_balance(node->left) >= 0)
			return rotate_right(node);
		else
		{
			node->left = rotate_left(node->left);
			return rotate_right(node);
		}
	}

	if (balance < -1)
	{
		if (get_balance(node->right) <= 0)
			return rotate_left(node);
		else
		{
			node->right = rotate_right(node->right);
			return rotate_left(node);
		}
	}

	return node;
}

/**
 * rotate_left - Rotates a tree node to the left
 * @y: Pointer to the node to be rotated
 * Return: Pointer to the new root after rotation
 */
avl_t *rotate_left(avl_t *y)
{
	avl_t *x = y->right;
	avl_t *T2 = x->left;

	x->left = y;
	y->right = T2;

	return x;
}

/**
 * rotate_right - Rotates a tree node to the right
 * @x: Pointer to the node to be rotated
 * Return: Pointer to the new root after rotation
 */
avl_t *rotate_right(avl_t *x)
{
	avl_t *y = x->left;
	avl_t *T2 = y->right;

	y->right = x;
	x->left = T2;

	return y;
}

/**
 * get_balance - Gets the balance factor of a tree node
 * @node: Pointer to the tree node
 * Return: Balance factor of the node
 */
int get_balance(avl_t *node)
{
	int left_height = (node->left == NULL) ? 0 : 1;
	int right_height = (node->right == NULL) ? 0 : 1;

	return left_height - right_height;
}

