#include "binary_trees.h"
#include <stdlib.h>

/**
 * delete_binary_tree - Deletes an entire binary tree
 * @treeRoot: Pointer to the root node of the tree to delete
 *
 * Description: Recursively deletes the entire binary tree starting from the root node.
 *
 * Return: void
 */
void delete_binary_tree(binary_tree_t *treeRoot)
{
    if (treeRoot == NULL)
        return;

    delete_binary_tree(treeRoot->left);
    delete_binary_tree(treeRoot->right);
    free(treeRoot);
}

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * Description: Deletes the entire binary tree starting from the root node.
 *
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
    delete_binary_tree(tree);
}
