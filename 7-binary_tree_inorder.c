#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses the binary tree using in-order
 *                       traversal.
 * @tree: The tree to traverse.
 * @func: A function pointer to print the value of the node in the tree.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
