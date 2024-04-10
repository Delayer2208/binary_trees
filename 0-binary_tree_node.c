#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Create a new binary tree node
 * @parent: Pointer to the parent node of the new node
 * @value: Value to store in the new node
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    /* Allocate memory for the new node */
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

    /* If malloc fails, return NULL */
    if (new_node == NULL)
        return (NULL);

    /* Initialize the new node */
    new_node->parent = parent;
    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;

    /* Return a pointer to the new node */
    return (new_node);
}
