#include "binary_trees.h"


/* helper function */
int is_full(const binary_tree_t *);

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: The tree to check.
 * Return: If the tree is full - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full;

	if (tree == NULL)
		return (0);

	full = is_full(tree);
	if (full > 1)
		full = 1;

	return (full);
}


/**
 * is_full - Checks if a binary tree is full.
 * @tree: The tree to check.
 * Return: If the tree is not full - 0.
 *         Otherwise - A value greater than 0.
 */
int is_full(const binary_tree_t *tree)
{
	int left = 1, right = 1;

	if (tree == NULL)
		return (0);

	left += is_full(tree->left);
	right += is_full(tree->right);
	if (!tree->left || !tree->right)
		return (0);

	return (left & right);
}
