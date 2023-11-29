#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int found_null = 0, complete = 1;
	const binary_tree_t **queue, *current;
	int front = 0, rear = 0;

	if (tree == NULL)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * 1000);
	if (queue == NULL)
		return (0);
	queue[rear++] = tree;
	while (front < rear)
	{
		current = queue[front++];
		if (current->left)
		{
			if (found_null)
			{
				complete = 0;
				break;
			}
			queue[rear++] = current->left;
		}
		else
			found_null = 1;

		if (current->right)
		{
			if (found_null)
			{
				complete = 0;
				break;
			}
			queue[rear++] = current->right;
		}
		else
			found_null = 1;
	}
	free(queue);
	return (complete);
}
