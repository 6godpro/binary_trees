#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses the binary tree using pre-order
 *                        traversal.
 * @tree: The tree to traverse.
 * @func: A function pointer to print the value of the node in the tree.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
