#include "binary_trees.h"


/**
 * find_ancestor - Find the Lowest common ancestor of the two given nodes.
 * @root: The root node of the tree.
 * @first: The first node.
 * @second: The second node.
 * Return: The Lowest Common Ancestor(LCA) if found, otherwise NULL.
 */
binary_tree_t *find_ancestor(const binary_tree_t *root,
			     const binary_tree_t *first,
			     const binary_tree_t *second)
{
	binary_tree_t *left, *right;
	
	if (root == NULL)
		return (NULL);

	if (root == first || root == second)
		return ((binary_tree_t *)root);

	if (!root->left && !root->right)
		return (NULL);

	left = find_ancestor(root->left, first, second);
	right = find_ancestor(root->right, first, second);
	if (left && right)
		return ((binary_tree_t *)root);

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
	binary_tree_t *root = (binary_tree_t *)first;

	if (!first || !second)
		return (NULL);

	while (root->parent)
		root = root->parent;
	return (find_ancestor(root, first, second));
}
