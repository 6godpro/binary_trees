#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node to the right of another node.
 * @parent: A pointer to node to a right child in.
 * @value: The value to assign to the new node.
 * Return: On failure - NULL.
 *         Otherwise - A pointer to the new node.
 * Desc: If parent already has a left child, this new node just take its place
 *       and the old left must be set to the left child of this new child.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;

	if (parent->right)
	{
		node->right = parent->right;
		parent->right->parent = node;
	}
	else
		node->right = NULL;
	parent->right = node;

	return (node);
}
