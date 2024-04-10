#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The size of the tree, or 0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * @index: The index of the current node.
 * @nodes: The total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree, size_t index, size_t nodes)
{
    if (tree == NULL)
        return (1);

    if (index >= nodes)
        return (0);

    return (binary_tree_is_complete(tree->left, 2 * index + 1, nodes) &&
            binary_tree_is_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (!binary_tree_is_complete(tree, 0, binary_tree_size(tree)))
        return (0);

    if (tree->left != NULL && tree->left->n > tree->n)
        return (0);

    if (tree->right != NULL && tree->right->n > tree->n)
        return (0);

    return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
}
