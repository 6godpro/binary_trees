#include "binary_trees.h"

/* Helper functions */
int max_value(int, int);
int get_height(const binary_tree_t *);

/**
 * binary_tree_height - Retrieves the height of a binary tree.
 * @tree: The tree to get the height of.
 * Return: If the tree does not have a height - 0.
 *         Otherwise - The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (get_height(tree) - 1);
}

/**
 * max_value - Returns the maximum of two values.
 * @x: The first value.
 * @y: The second value.
 * Return: The maximum of the two values.
 */
int max_value(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

/**
 * get_height - Gets the height of a binary tree.
 * @tree: The tree to get the height of.
 * Return: The height of the tree.
 */
int get_height(const binary_tree_t *tree)
{
	size_t right_child_height, left_child_height;

	if (tree == NULL)
		return (0);

	left_child_height = get_height(tree->left);
	right_child_height = get_height(tree->right);
	return (1 + max_value(left_child_height, right_child_height));
}
