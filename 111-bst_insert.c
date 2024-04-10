#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Description:
 * If the address stored in `tree` is NULL, the created node becomes the root node.
 * If the value is already present in the tree, it is ignored.
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current_node;

    if (!tree)
        return NULL;

    if (!(*tree))
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }

    current_node = *tree;
    while (current_node)
    {
        if (current_node->n == value)
            return NULL; // Value already exists, return NULL

        if (value < current_node->n)
        {
            if (!(current_node->left))
            {
                new_node = binary_tree_node(current_node, value);
                current_node->left = new_node;
                return new_node;
            }
            current_node = current_node->left;
        }
        else
        {
            if (!(current_node->right))
            {
                new_node = binary_tree_node(current_node, value);
                current_node->right = new_node;
                return new_node;
            }
            current_node = current_node->right;
        }
    }

    return NULL; // Should not reach here, added for completeness
}
