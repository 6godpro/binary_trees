#include "binary_trees.h"


/* helper functions */
int get_max(int x, int y);
int _pow(int base, int exp);
int get_height(const binary_tree_t *tree);
int count_leaves(const binary_tree_t *tree);


/**
 * binary_tree_is_perfect - Checks if a given binary tree is perfect.
 * @tree: The tree to be checked.
 * Return: If the tree is not perfect - 0.
 *         Otherwise - 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, actual_leaves, expected_leaves;

	if (tree == NULL)
		return (0);

	height = get_height(tree);
	actual_leaves = count_leaves(tree);

	expected_leaves = _pow(2, height - 1);

	if (actual_leaves != expected_leaves)
		return (0);

	return (1);
}

/**
 * _pow - Finds the power of the given base with the exponent.
 * @base: The base to be computed.
 * @exp: The value with which to compute the power (exponent).
 * Return: The computed result.
 */
int _pow(int base, int exp)
{
	int result = 1;

	if (exp == 0)
		return (1);
	while (exp)
	{
		result *= base;
		exp--;
	}
	return (result);
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

/**
 * count_leaves - Counts the leaves in a binary tree.
 * @tree: The tree to count the number of leaves.
 * Return: If the tree is NULL - 0.
 *         Otherwise - The number of leaves.
 */
int count_leaves(const binary_tree_t *tree)
{
	int l, r;

	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	l = count_leaves(tree->left);
	r = count_leaves(tree->right);

	return (l + r);
}
