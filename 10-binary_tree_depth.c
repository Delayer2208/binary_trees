#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @node: Pointer to the node to measure the depth of
 *
 * Return: Depth of a node in a binary tree. If node is NULL, return 0
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
    size_t depth_count = 0; // Initialize depth count to zero

    if (node == NULL)
        return (depth_count); // If node is NULL, return 0

    // Traverse up the tree until reaching the root while counting the steps
    while (node->parent != NULL)
    {
        depth_count++; // Increment depth count
        node = node->parent; // Move to the parent node
    }

    return (depth_count); // Return the depth of the node
}
