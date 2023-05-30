#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes with at least 1 child.
 * @tree: The tree to count the number of nodes.
 * Return: If the tree is NULL - 0.
 *         Otherwise - The number of nodes.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes, right_nodes;

	if (tree == NULL)
		return (0);

	left_nodes = binary_tree_nodes(tree->left);
	right_nodes = binary_tree_nodes(tree->right);

	if (tree->left || tree->right)
		return (1 + left_nodes + right_nodes);

	return (0 + left_nodes + right_nodes);
}
