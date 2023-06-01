#include "binary_trees.h"


/**
 * array_to_bst - Creates a BST from an array.
 * @array: Array from which the tree is to be built.
 * @size: The size of the array.
 *
 * Return: On success - A pointer to the root node of the tree.
 *         Otherwise - NULL.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i = 0;

	if (array == NULL || size <= 0)
		return (NULL);

	while (i < size)
		bst_insert(&root, array[i++]);
	return (root);
}
