#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Description: If a value of the array already exists, it is ignored
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *root = NULL;

    if (array == NULL || size == 0)
        return NULL;

    for (size_t i = 0; i < size; i++)
    {
        if (bst_insert(&root, array[i]) == NULL)
        {
            /* Clean up on failure */
            while (root != NULL)
            {
                bst_t *temp = root;
                root = root->left;
                free(temp);
            }
            return NULL;
        }
    }

    return root;
}
