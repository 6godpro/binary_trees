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
 * is_empty - Checks if a given queue is empty.
 * @queue: The queue to be checked.
 * Return: If the queue is empty - 1.
 *         Otherwise - 0.
 */
int is_empty(queue_t *queue)
{
	return ((queue == NULL) ? 1 : 0);
}

/**
 * remove_from_queue - Removes an item from a queue.
 * @queue: The queue from which an item is to be removed.
 */
void remove_from_queue(queue_t **queue)
{
	queue_t *tmp;

	if (is_empty(*queue))
		return;

	tmp = *queue;
	*queue = (*queue)->next;
	free(tmp);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using
 *                          level-order traversal.
 * @tree: The tree to be traversed.
 * @func: A function to print the data at each visited node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;
	binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;

	queue = create_queue();
	if (queue == NULL)
		return;

	push_to_queue(&queue, (binary_tree_t *)tree);

	while (!is_empty(queue))
	{
		current = queue->node;
		func(current->n);

		if (current->left)
			push_to_queue(&queue, current->left);
		if (current->right)
			push_to_queue(&queue, current->right);

		remove_from_queue(&queue);
	}
	free(queue);
}
