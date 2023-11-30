#include "binary_trees.h"

bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            bst_t *temp = root->right;
            // Print the tree before freeing the node
            binary_tree_print(root);
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            bst_t *temp = root->left;
            // Print the tree before freeing the node
            binary_tree_print(root);
            free(root);
            return temp;
        }

        // Node with two children: Get the in-order successor (smallest
        // in the right subtree) and copy its value to this node
        bst_t *temp = find_minimum(root->right);
        root->n = temp->n;

        // Delete the in-order successor
        root->right = bst_remove(root->right, temp->n);
    }

    return root;
}

