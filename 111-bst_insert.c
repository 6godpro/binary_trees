#include "binary_trees.h"


/**
 * place_node - Sets a node to given tree node.
 * @tree: The tree to which the node is to be set on.
 * @value: The value of the node to be set.
 * @flag: A sentinel value denoting where the node is to
 *        be set.
 *        0 - The node should be set directly as the tree.
 *        1 - The node should be set as the left child.
 *        2 - The node should be set as the right child.
 * Return: On success - A pointer to the newly created node.
 *         Otherwise - NULL.
 */
bst_t *place_node(bst_t **tree, int value, int flag)
{
	bst_t *node;

	node = binary_tree_node(*tree, value);
	if (node != NULL)
	{
		if (flag == 0)
			*tree = node;
		else if (flag == 1)
			(*tree)->left = node;
		else if (flag == 2)
			(*tree)->right = node;
		return (node);
	}
	return (NULL);
}


/**
 * bst_insert - Inserts a node into a BST.
 * @tree: A double pointer to the root node of the BST to
 *        to which the node is to be inserted.
 * @value: The value to be inserted in the new node.
 * Return: On success - A pointer to the newly created node.
 *         Otherwise - NULL.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
		return (place_node(tree, value, 0));

	if ((*tree)->n > value)
	{
		if ((*tree)->left)
			return (bst_insert(&(*tree)->left, value));
		return (place_node(tree, value, 1));
	}

	if ((*tree)->n < value)
	{
		if ((*tree)->right)
			return (bst_insert(&(*tree)->right, value));
		return (place_node(tree, value, 2));
	}
	return (NULL);
}
