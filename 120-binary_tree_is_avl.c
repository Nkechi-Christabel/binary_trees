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

typedef struct AVLData {
    int height;
    int is_AVL;
} AVLData;

int maxInt(int a, int b) {
    return (a > b) ? a : b;
}

AVLData getAVLData(const binary_tree_t *tree) {
    AVLData left, right, node;

    if (!tree) {
        node.height = -1;
        node.is_AVL = 1;
        return node;
    }

    left = getAVLData(tree->left);
    right = getAVLData(tree->right);

    node.height = 1 + maxInt(left.height, right.height);

    int balFactor = right.height - left.height;
    node.is_AVL = (balFactor >= -1 && balFactor <= 1) && left.is_AVL && right.is_AVL;

    return node;
}

int isBST(const binary_tree_t *tree, int min, int max, int *prev) {
    if (!tree)
        return 1;

    if (tree->n <= min || tree->n >= max)
        return 0;

    if (!isBST(tree->left, min, tree->n, prev))
        return 0;

    if (*prev != -1 && tree->n <= *prev)
        return 0;

    *prev = tree->n;

    return isBST(tree->right, tree->n, max, prev);
}

int isAVL(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max) {
    if (!tree)
        return 1;

    size_t leftHeight = binary_tree_height(tree->left);
    size_t rightHeight = binary_tree_height(tree->right);

    if (max && (rightHeight - leftHeight) > binary_tree_height(max))
        return 0;

    if (min && (leftHeight - rightHeight) > binary_tree_height(min))
        return 0;

    return isAVL(tree->left, min, tree) && isAVL(tree->right, tree, max);
}

int binary_tree_is_avl(const binary_tree_t *tree) {
    int prev = -1;

    if (!tree)
        return 0;

    if (!isBST(tree, INT_MIN, INT_MAX, &prev))
        return 0;

    return getAVLData(tree).is_AVL;
}
