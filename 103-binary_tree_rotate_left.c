#include "binary_trees.h"


/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to be rotated.
 * Return: On failure - NULL.
 *         Otherwise - A pointer to the new root node.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_parent, *tmp = NULL;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_parent = tree->right;
	tmp = new_parent->left;

	new_parent->left = tree;
	tree->right = tmp;
	if (tmp)
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
