#include "binary_trees.h"


/**
 * find_root - Finds the parent node of the given node.
 * @node: The node to find its parent.
 * Return: The parent if found, otherwise NULL.
 */
binary_tree_t *find_root(binary_tree_t *node)
{
	binary_tree_t *tmp = node;

	if (node == NULL)
		return (NULL);

	while (tmp->parent)
		tmp = tmp->parent;

	return (tmp);
}

/**
 * find_ancestor - Find the Lowest common ancestor of the two given nodes.
 * @root: The root node of the tree.
 * @first: The first node.
 * @second: The second node.
 * Return: The Lowest Common Ancestor(LCA) if found, otherwise NULL.
 */
binary_tree_t *find_ancestor(binary_tree_t *root,
			     const binary_tree_t *first,
			     const binary_tree_t *second)
{
	binary_tree_t *left, *right;

	if (root == first || root == second)
		return (root);

	if (!root->left && !root->right)
		return (NULL);

	left = find_ancestor(root->left, first, second);
	right = find_ancestor(root->right, first, second);
	if (left && right)
		return (root);

	return ((left == NULL) ? right : left);
}


/**
 * binary_trees_ancestor - Find the Lowest common ancestor of the two given
 *                         nodes.
 * @first: The first node.
 * @second: The second node.
 * Return: The Lowest Common Ancestor(LCA) if found, otherwise NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *root;

	if (!first || !second)
		return (NULL);

	root = find_root((binary_tree_t *)first);
	if (root)
		return (find_ancestor(root, first, second));

	return (NULL);
}
