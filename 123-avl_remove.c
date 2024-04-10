#include "binary_trees.h"

/**
 * balance_avl - Rebalances the AVL tree after removal.
 * @tree: Pointer to the root node of the AVL tree.
 */
void balance_avl(avl_t **tree)
{
	int balance_factor;

	if (tree == NULL || *tree == NULL)
		return;

	balance_avl(&(*tree)->left);
	balance_avl(&(*tree)->right);

	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * find_successor - Finds the inorder successor in the BST.
 * @node: Pointer to the node for which to find the successor.
 * Return: Value of the inorder successor.
 */
int find_successor(bst_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL)
		return (node->n);

	return find_successor(node->left);
}

/**
 * remove_node - Removes the specified node from the BST.
 * @node: Pointer to the node to remove.
 * Return: 0 if node has no children, 1 otherwise.
 */
int remove_node(bst_t *node)
{
	if (!node->left && !node->right)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		return 0;
	}
	else if (!node->left || !node->right)
	{
		bst_t *child = node->left ? node->left : node->right;

		if (node->parent->left == node)
			node->parent->left = child;
		else
			node->parent->right = child;
		child->parent = node->parent;
		free(node);
		return 0;
	}
	else
	{
		int successor_value = find_successor(node->right);
		node->n = successor_value;
		return 1;
	}
}

/**
 * bst_remove - Removes a node from the BST.
 * @root: Pointer to the root node of the BST.
 * @value: Value to remove from the BST.
 * Return: Pointer to the root node after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int removed = 0;

	if (root == NULL)
		return NULL;

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		removed = remove_node(root);
		if (removed != 0)
			bst_remove(root->right, removed);
	}
	return root;
}

/**
 * avl_remove - Removes a node from the AVL tree.
 * @root: Pointer to the root node of the AVL tree.
 * @value: Value to remove from the AVL tree.
 * Return: Pointer to the root node after removal and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *new_root = (avl_t *) bst_remove((bst_t *) root, value);

	if (new_root == NULL)
		return NULL;

	balance_avl(&new_root);
	return new_root;
}
