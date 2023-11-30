#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 *
 * @root: Pointer to the root node of the tree where the node will be removed
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of the tree after removing the
 * desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *temp_right, *temp_left;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
		else if (value > root->n)
		{
			root->right = bst_remove(root->right, value);
			if (root->right)
				root->right->parent = root;
		}
	else
	{
		if (root->left == NULL)
		{
			temp_right = root->right;
			free(root);
			return (temp_right);
		}
		else if (root->right == NULL)
		{
			temp_left = root->left;
			free(root);
			return (temp_left);
		}
		temp = root->right;
		while (temp->left != NULL)
			temp = temp->left;
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
		if (root->right)
			root->right->parent = root;
		return (root);
	}
	return (root);
}

