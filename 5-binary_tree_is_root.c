#include "binary_trees.h"

/**
 * is_root_node - Checks if a given node is a root
 * @node: Pointer to the node to check
 *
 * Description: Returns 1 if the node is a root, and 0 otherwise. If the node is NULL, returns 0.
 *
 * Return: 1 if node is a root, and 0 otherwise. If node is NULL, returns 0
 */
int is_root_node(const binary_tree_t *node)
{
    if (node != NULL && node->parent == NULL)
        return (1);
    return (0);
}

/**
 * binary_tree_is_root - Checks if a given node is a root
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a root, and 0 otherwise. If node is NULL, returns 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
    return is_root_node(node);
}
