#include "binary_trees.h"


/**
 * create_queue - Creates a queue.
 * Return: On failure - NULL.
 *         Otherwise - A pointer to the newly created queue.
 */
queue_t *create_queue()
{
	queue_t *queue;

	queue = malloc(sizeof(queue_t));
	if (queue == NULL)
		return (NULL);

	queue->node = NULL;
	queue->next = NULL;

	return (queue);
}

/**
 * enqueue - Prepends a BST node to a queue.
 * @queue: A pointer to the queue to which the nodes are to be prepended.
 * @node: A pointer to the node to be prepended.
 */
void enqueue(queue_t **queue, binary_tree_t *node)
{
	queue_t *tmp = *queue, *new_queue;

	if (*queue == NULL || node == NULL)
		return;

	if ((*queue)->node == NULL)
	{
		(*queue)->node = node;
		(*queue)->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		new_queue = malloc(sizeof(queue_t));
		if (new_queue)
		{
			new_queue->node = node;
			new_queue->next = NULL;
		}
		tmp->next = new_queue;
	}
}

/**
 * bst_to_queue - Converts a binary search tree to a queue.
 * @root: A pointer to a subtree node of a BST.
 * @queue: A pointer to the queue to which the node are to be appended.
 */
void bst_to_queue(const binary_tree_t *root, queue_t **queue)
{
	if (root == NULL)
		return;

	bst_to_queue(root->left, queue);
	enqueue(queue, (binary_tree_t *)root);
	bst_to_queue(root->right, queue);
}

/**
 * validate_queue - Checks if a items in a queue are in ascending order.
 * @queue: The queue to be validated.
 * Return: If it is valid - 1.
 *         Otherwise - 0.
 */
int validate_queue(const queue_t *queue)
{
	queue_t *tmp = (queue_t *)queue;

	while (tmp)
	{
		if (tmp->next &&
		    (tmp->node->n >= tmp->next->node->n))
			break;
		tmp = tmp->next;
	}
	return (tmp ? 0 : 1);
}

/**
 * binary_tree_is_bst - Checks if a tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to be checked.
 * Return: If it is valid - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	queue_t *queue, *tmp;
	int valid;

	if (tree == NULL)
		return (0);

	queue = create_queue();
	if (queue == NULL)
		return (-1);

	bst_to_queue(tree, &queue);
	valid = validate_queue(queue);
	while (queue)
	{
		tmp = queue->next;
		free(queue);
		queue = tmp;
	}

	return (valid ? 1 : 0);
}
