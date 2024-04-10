#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created Binary Heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
    heap_t *tree = NULL;
    size_t i;

    if (!array || size == 0)
        return NULL;

    for (i = 0; i < size; i++)
    {
        if (!heap_insert(&tree, array[i]))
            return NULL; // If insertion fails, return NULL
    }

    return tree;
}
