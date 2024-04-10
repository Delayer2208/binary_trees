#include "binary_trees.h"

/**
 * preorder_traversal - Traverses a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 *        The value in the node must be passed as a parameter to this function
 *
 * Description: This function traverses the binary tree using pre-order traversal
 *              and applies the provided function to each node.
 *
 * Return: void
 */
void preorder_traversal(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    func(tree->n);
    preorder_traversal(tree->left, func);
    preorder_traversal(tree->right, func);
}

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 *        The value in the node must be passed as a parameter to this function
 *
 * Description: This function is a wrapper around preorder_traversal function.
 *
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    preorder_traversal(tree, func);
}
