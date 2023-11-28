#include "binart_trees.h"

/**
* binary_tree_node - Create a new binary tree node
*
* parent: is a pointer to the parent node of the node to create
* value: value to put in the new node
* Return: new node
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	struct node* newNode;

	if (parent == NULL)
		return (NULL);
  	newNode = malloc(sizeof(struct node));
	newNode->n = value;
	newNode->parent = parent
  	newNode->left = NULL;
  	newNode->right = NULL;

  	return (newNode);
}
