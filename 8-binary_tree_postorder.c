#include "binary_trees.h"

/**
 * postorder_traversal - traverses a binary tree using postorder traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 *
 * Return: void
 */
void postorder_traversal(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	postorder_traversal(tree->left, func);
	postorder_traversal(tree->right, func);
	func(tree->n);
}
