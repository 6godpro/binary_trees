#include "binary_trees.h"

/* Helper functions */
int get_depth(const binary_tree_t *);

/**
 * binary_tree_depth - Retrieves the depth of a node in a binary tree.
 * @tree: The tree to get the depth of.
 * Return: If the node does not have a depth - 0.
 *         Otherwise - The depth of the tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (get_depth(tree) - 1);
}

/**
 * get_depth - Gets the depth of a node in a binary tree.
 * @tree: The tree to get the depth of.
 * Return: The depth of the tree.
 */
int get_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = get_depth(tree->parent);
	return (1 + depth);
}
