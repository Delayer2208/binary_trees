#include "binary_trees.h"

/**
 * is_leaf_node - Checks if a node is a leaf
 * @node: Pointer to the node to check
 *
 * Description: Returns 1 if the node is a leaf, and 0 otherwise. If the node is NULL, returns 0.
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, returns 0
 */
int is_leaf_node(const binary_tree_t *node)
{
    if (node != NULL && node->left == NULL && node->right == NULL)
        return (1);
    return (0);
}

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, returns 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    return is_leaf_node(node);
}
