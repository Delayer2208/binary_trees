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
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Description: If parent already has a right-child, the new node must take its
 * place, and the old right-child must be set as the right-child of the new node.
 *
 * Return: Pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *rightChild;

    if (parent == NULL)
        return (NULL);

    rightChild = create_binary_tree_node(parent, value);
    if (rightChild == NULL)
        return (NULL);

    rightChild->right = parent->right;
    if (rightChild->right != NULL)
        rightChild->right->parent = rightChild;

    parent->right = rightChild;

    return (rightChild);
}
