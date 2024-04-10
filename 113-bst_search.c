#include "binary_trees.h"

/**
 * @brief Searches for a value in a binary search tree.
 *
 * @param tree Pointer to the root node of the BST to search.
 * @param value Value to search in the tree.
 * @return Pointer to the node containing a value equal to `value`, or NULL if not found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    bst_t *tmp = (bst_t *)tree;

    while (tmp)
    {
        if (tmp->n == value)
        {
            return tmp;
        }
        else if (tmp->n < value)
        {
            tmp = tmp->right;
        }
        else
        {
            tmp = tmp->left;
        }
    }

    return NULL;
}
