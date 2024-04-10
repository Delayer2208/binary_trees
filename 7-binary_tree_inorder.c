#include "binary_trees.h"

/**
 * inorder_traversal - Traverses a binary tree using in-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 *        The value in the node must be passed as a parameter to this function
 *
 * Description: This function traverses the binary tree using in-order traversal
 *              and applies the provided function to each node.
 *
 * Return: void
 */
void inorder_traversal(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    inorder_traversal(tree->left, func);
    func(tree->n);
    inorder_traversal(tree->right, func);
}

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 *        The value in the node must be passed as a parameter to this function
 *
 * Description: This function is a wrapper around inorder_traversal function.
 *
 * Return: void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    inorder_traversal(tree, func);
}
