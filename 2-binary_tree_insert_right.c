#include "binary_trees.h"

/**
 * binary_tree_insert_right - a function that inserts a node as the right-child
 *@parent: a pointer to the node to insert the right-child in.
 *@value: the value to store in the new node.
 * Return: newNode, or NULL on failure or if parent is NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL)
		return (NULL);
	newNode = malloc(sizeof(binary_tree_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	if (parent->right == NULL)
		parent->right = newNode;
	else
	{
		newNode->right = parent->right;
		parent->right = newNode;
		newNode->right->parent = newNode;
	}
	return (newNode);
}
