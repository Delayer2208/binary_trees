#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling of
 *
 * Return: pointer to the sibling node, or NULL if no sibling exists
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return (NULL);

    binary_tree_t *parent = node->parent;
    if (node == parent->left)
        return (parent->right);
    else
        return (parent->left);
}
