#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverses a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t height, i;

    if (tree == NULL || func == NULL)
        return;
    height = binary_tree_height(tree);
    for (i = 1; i <= height; i++)
        binary_tree_level(tree, i, func);
}
