#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree.
 * @tree: A pointer to the root node of the tree to be searched.
 * @value: The value to be searched for.
 * Return: On success - A pointer to the node with the value being
 *                      searched for.
 *         Otherwise - NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	if (tree->n > value)
		return (bst_search(tree->left, value));

	if (tree->n < value)
		return (bst_search(tree->right, value));

	return (NULL);
}
