#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: The tree to count the number of leaves.
 * Return: If the tree is NULL - 0.
 *         Otherwise - The number of leaves.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_leaves, right_leaves;

	if (tree == NULL)
		return (0);

	left_leaves =  binary_tree_leaves(tree->left);
	right_leaves =  binary_tree_leaves(tree->right);
	if (tree->left || tree->right)
		return (0 + right_leaves + left_leaves);

	return (1 + right_leaves + left_leaves);
}
