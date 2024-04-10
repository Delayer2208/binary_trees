#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (node != NULL && node->left == NULL && node->right == NULL)
        return (1); // Node is a leaf
    return (0); // Node is not a leaf
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the leaves in
 *
 * Description: A NULL pointer is not a leaf
 *
 * Return: number of leaves in a binary tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    size_t left_leaves, right_leaves;

    if (tree == NULL)
        return (0); // Empty tree has no leaves

    if (binary_tree_is_leaf(tree))
        return (1); // Current node is a leaf

    // Recursively count leaves in left and right subtrees
    left_leaves = binary_tree_leaves(tree->left);
    right_leaves = binary_tree
