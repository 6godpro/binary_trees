#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: The node to find its uncle.
 * Return: If the node is NULL - NULL.
 *         If the node has no uncle - NULL.
 *         Otherwise - The uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
