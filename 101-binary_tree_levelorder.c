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
    if (tree == NULL || func == NULL)
        return;

    binary_tree_level_recursive(tree, 1, func);
}

/**
 * binary_tree_level_recursive - recursive function to process nodes at a specific level
 * @tree: pointer to the root node of the tree to process
 * @level: the level of the tree to process
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 *
 * Return: void
 */
void binary_tree_level_recursive(const binary_tree_t *tree, int level, void (*func)(int))
{
    if (tree == NULL)
        return;

    if (level == 1)
        func(tree->n);
    else if (level > 1)
    {
        binary_tree_level_recursive(tree->left, level - 1, func);
        binary_tree_level_recursive(tree->right, level - 1, func);
    }