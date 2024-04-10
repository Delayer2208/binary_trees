#include "binary_trees.h"

/**
 * binary_tree_level - traverses a binary tree using level-order traversal
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

/**
 * binary_tree_level - processes a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to process
 * @level: the level of the tree to process
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 *
 * Return: void
 */
void binary_tree_level(const binary_tree_t *tree, int level, void (*func)(int))
{
    if (tree == NULL)
        return;

    if (level == 1)
        func(tree->n);
    else if (level > 1)
    {
        binary_tree_level(tree->left, level - 1, func);
        binary_tree_level(tree->right, level - 1, func);
    }
    else
        return;
}