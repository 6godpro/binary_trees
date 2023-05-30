#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses the binary tree using post-order
 *                        traversal.
 * @tree: The tree to traverse.
 * @func: A function pointer to print the value of the node in the tree.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
