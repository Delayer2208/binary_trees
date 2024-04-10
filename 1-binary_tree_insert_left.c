#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_binary_tree_node - Creates a binary tree node
 * @parentNode: Pointer to the parent node of the new node
 * @nodeValue: Value to store in the new node
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *create_binary_tree_node(binary_tree_t *parentNode, int nodeValue)
{
    binary_tree_t *newNode = malloc(sizeof(binary_tree_t));

    if (newNode == NULL)
        return (NULL);

    newNode->parent = parentNode;
    newNode->n = nodeValue;
    newNode->left = NULL;
    newNode->right = NULL;

    return (newNode);
}

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Description: If parent already has a left-child, the new node must take its
 * place, and the old left-child must be set as the left-child of the new node.
 *
 * Return: Pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *leftChild;

    if (parent == NULL)
        return (NULL);

    leftChild = create_binary_tree_node(parent, value);
    if (leftChild == NULL)
        return (NULL);

    leftChild->left = parent->left;
    if (leftChild->left != NULL)
        leftChild->left->parent = leftChild;

    parent->left = leftChild;

    return (leftChild);
}
