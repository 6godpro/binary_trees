#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: The tree to measure the balance factor.
 * Return: If the tree has no children - 0.
 *         If the tree has only one child - -1.
 *         Otherwise - 2.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree->left && tree->right)
		return (2);

	if (!tree->left && !tree->right)
		return (0);

	return (-1);
}
