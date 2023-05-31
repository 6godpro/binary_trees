#include "binary_trees.h"

/**
 * create_queue - creates a queue structure.
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
 * push_to_queue - Adds an item to a queue.
 * @queue: The queue to which an item is to be added.
 * @node: The node item to be added to the queue.
 */
void push_to_queue(queue_t **queue, binary_tree_t *node)
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
		new_queue = create_queue();
		if (new_queue)
		{
			new_queue->node = node;
			new_queue->next = NULL;
		}
		tmp->next = new_queue;
	}
}

/**
 * remove_from_queue - Removes an item from a queue.
 * @queue: The queue from which an item is to be removed.
 */
void remove_from_queue(queue_t **queue)
{
	queue_t *tmp;

	if (*queue == NULL)
		return;

	tmp = *queue;
	*queue = (*queue)->next;
	free(tmp);
}

/**
 * is_valid - Checks if a node is a valid complete node.
 * @queue: The queue to the prepend a node to if it is valid.
 * @node: The node to validate.
 * @flag: A sentinel value indicating the validity of a node.
 * Return: If the node is valid - 1.
 *         Otherwise - 0.
 */
int is_valid(queue_t *queue, const binary_tree_t *node, int *flag)
{
	if (node->left)
	{
		/* Occurrence of Right node without Left node */
		if (*flag == 1)
			return (0);
		push_to_queue(&queue, node->left);
	}
	else
		*flag = 1;

	if (node->right)
	{
		/* Occurence of Left node without Right node */
		if (*flag == 1)
			return (0);
		push_to_queue(&queue, node->right);
	}
	else
		*flag = 1;
	return (1);
}


/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: The tree to be checked.
 * Return: If the tree is not complete - 0.
 *         Otherwise - 1.
 * This function returns -1 if the queue fails to initialize.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *queue, *tmp;
	int flag = 0, valid;

	if (tree == NULL)
		return (0);

	queue = create_queue();
	if (queue == NULL)
		return (-1);

	push_to_queue(&queue, (binary_tree_t *)tree);

	while (queue)
	{
		valid = is_valid(queue, queue->node, &flag);
		if (valid == 0)
			break;
		remove_from_queue(&queue);
	}

	if (valid == 0)
	{
		while (queue)
		{
			tmp = queue->next;
			free(queue);
			queue = tmp;
		}
		return (0);
	}
	return (1);
}
