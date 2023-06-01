#include "binary_trees.h"


/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to be rotated.
 * Return: On failure - NULL.
 *         Otherwise - A pointer to the new root node.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_parent, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	new_parent = tree->left;
	tmp = new_parent->right;

	new_parent->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = new_parent;
	new_parent->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = new_parent;
		else
			tmp->right = new_parent;
	}
	return (new_parent);
}
