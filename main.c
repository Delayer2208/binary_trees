#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *uncle;

    // Test case 1: Node has an uncle
    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->right = binary_tree_node(root->right, 402);
    root->left->left = binary_tree_node(root->left, 10);
    root->right->left = binary_tree_node(root->right, 110);
    root->right->right->left = binary_tree_node(root->right->right, 200);
    root->right->right->right = binary_tree_node(root->right->right, 512);

    binary_tree_print(root);
    uncle = binary_tree_uncle(root->right->left);
    printf("Uncle of %d: %d\n", root->right->left->n, uncle->n); // Expected output: Uncle of 110: 12

    // Test case 2: Node has no uncle
    uncle = binary_tree_uncle(root->left->right);
    printf("Uncle of %d: %d\n", root->left->right->n, uncle->n); // Expected output: Uncle of 54: 128

    // Test case 3: Root node has no uncle
    uncle = binary_tree_uncle(root);
    printf("Uncle of %d: %p\n", root->n, (void *)uncle); // Expected output: Uncle of 98: (nil)

    // Test case 4: Node is NULL
    uncle = binary_tree_uncle(NULL);
    printf("Uncle of NULL: %p\n", (void *)uncle); // Expected output: Uncle of NULL: (nil)

    // Test case 5: Node has no parent or grandparent
    binary_tree_t *node = binary_tree_node(NULL, 10);
    uncle = binary_tree_uncle(node);
    printf("Uncle of %d: %p\n", node->n, (void *)uncle); // Expected output: Uncle of 10: (nil)

    return (0);
}
