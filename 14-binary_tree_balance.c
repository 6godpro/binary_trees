#include "binary_trees.h"

/* helper functions */
int get_height(const binary_tree_t *tree);
int get_max(int x, int y);

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: The tree to measure the balance factor.
 * Return: The balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	left = get_height(tree->left);
	right = get_height(tree->right);

	return (left - right);
}


/**
 * get_max - Returns the maximum of two values.
 * @x: The first value to compare.
 * @y: The second value to compare.
 * Return: The maximum of the two values.
 */
int get_max(int x, int y)
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
	int l, r;

	if (tree == NULL)
		return (0);

	l = get_height(tree->left);
	r = get_height(tree->right);

	return (1 + get_max(l, r));
}
