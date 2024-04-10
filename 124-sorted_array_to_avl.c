#include "binary_trees.h"

/**
 * create_tree - Recursively creates an AVL tree.
 *
 * @node: Pointer to the current node.
 * @array: Pointer to the input array of integers.
 * @start: Start index of the subarray.
 * @end: End index of the subarray.
 * Return: No return value.
 */
void create_tree(avl_t **node, int *array, size_t start, size_t end)
{
    if (start > end)
        return;

    size_t middle = (start + end) / 2;

    (*node) = binary_tree_node(NULL, array[middle]);

    if (*node == NULL)
        return;

    create_tree(&((*node)->left), array, start, middle - 1);
    create_tree(&((*node)->right), array, middle + 1, end);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 *
 * @array: Pointer to the input array of integers.
 * @size: Size of the array.
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return NULL;

    avl_t *root = NULL;
    create_tree(&root, array, 0, size - 1);

    return root;
}
