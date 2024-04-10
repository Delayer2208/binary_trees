#include "binary_trees.h"

/* Function prototypes */
size_t binary_tree_height(const binary_tree_t *tree);
heap_t *last_node_heap(const heap_t *tree, size_t level);
void heapify(heap_t *tree);

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 *                and rebalances the heap if necessary.
 *
 * @root: Pointer to the root node of the heap
 *
 * Return: Value of the extracted root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int value;
    size_t height;
    heap_t *first, *last;

    if (!root || !*root)
        return (0);

    first = *root;
    value = first->n;

    if (!(first->left || first->right))
    {
        *root = NULL;
        free(first);
        return (value);
    }

    /* Swap data between last node and first node and delete last node */
    height = binary_tree_height(*root);
    last = last_node_heap(*root, height);
    first->n = last->n;
    if (last->parent->left == last)
        last->parent->left = NULL;
    else
        last->parent->right = NULL;
    free(last);

    heapify(*root);

    return (value);
}

/**
 * heapify - Rearranges the Max Binary Heap to maintain the heap property
 *           after the root node is extracted.
 *
 * @tree: Pointer to the root node of the Max Binary Heap
 */
void heapify(heap_t *tree)
{
    int temp;

    if (!tree)
        return;

    temp = tree->n;

    if (tree->left && tree->n < tree->left->n &&
        (!tree->right || tree->left->n > tree->right->n))
    {
        tree->n = tree->left->n;
        tree->left->n = temp;
        heapify(tree->left);
    }
    if (tree->right && tree->n < tree->right->n &&
        tree->left->n < tree->right->n)
    {
        tree->n = tree->right->n;
        tree->right->n = temp;
        heapify(tree->right);
    }
}

/**
 * last_node_heap - Finds and returns the last node of the binary heap.
 *
 * @tree: The current node in the binary heap
 * @level: The current level of the node in the binary heap
 *
 * Return: Pointer to the last node of the binary heap
 */
heap_t *last_node_heap(const heap_t *tree, size_t level)
{
    heap_t *last = NULL;

    if (tree)
    {
        if (level == 0)
            return ((heap_t *)tree);
        last = last_node_heap(tree->right, level - 1) ?
               last_node_heap(tree->right, level - 1) :
               last_node_heap(tree->left, level - 1);
        return (last);
    }
    return (NULL);
}

/**
 * binary_tree_height - Calculates the height of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Height of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_left, height_right;

    if (!tree || !(tree->left || tree->right))
        return (0);

    height_left = binary_tree_height(tree->left);
    height_right = binary_tree_height(tree->right);

    return (1 + (height_left >= height_right ? height_left : height_right));
}
