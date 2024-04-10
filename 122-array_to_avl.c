#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
    size_t i;
    avl_t *root = NULL;

    if (size == 0 || array == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        size_t j;
        int duplicate = 0;

        for (j = 0; j < i; j++)
        {
            if (array[j] == array[i])
            {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate)
        {
            if (!avl_insert(&root, array[i]))
                return (NULL);
        }
    }

    return (root);
}
