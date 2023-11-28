#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function that inserts a node as the left-child
 *@parent: a pointer to the node to insert the left-child in.
 *@value: the value to store in the new node.
 * Return: newNode, or NULL on failure or if parent is NULL.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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

	if (parent->left == NULL)
		parent->left = newNode;
	else
	{
		newNode->left = parent->left;
		parent->left = newNode;
		newNode->left->parent = newNode;
	}
	return (newNode);
}
