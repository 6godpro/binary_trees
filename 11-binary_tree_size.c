#include "binary_trees.h"


/**
 * binary_tree_size - Retrieves the size of a binary tree.
 * @tree: The tree to get the size of.
 * Return: If tree is NULL - 0.
 *         Otherwise - The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_child_size, right_child_size;

	if (tree == NULL)
		return (0);

	left_child_size = binary_tree_size(tree->left);
	right_child_size = binary_tree_size(tree->right);
	return (1 + left_child_size + right_child_size);
}
