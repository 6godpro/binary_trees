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
 * free_queue - Frees a queue.
 * @queue: The queue to be freed.
 */
void free_queue(queue_t *queue)
{
	queue_t *tmp;

	while (queue)
	{
		tmp = queue->next;
		free(queue);
		queue = tmp;
	}
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
	queue_t *queue;
	binary_tree_t *current;

	if (tree == NULL)
		return (0);

	queue = create_queue();
	if (queue == NULL)
		return (-1);

	push_to_queue(&queue, (binary_tree_t *)tree);

	while (queue)
	{
		current = queue->node;
		if (current->left && current->right)
		{
			push_to_queue(&queue, current->left);
			push_to_queue(&queue, current->right);
		}
		else if (current->left && !current->right)
		{
			if (current->parent && current->parent->right
			    && (current->parent->right->left ||
				current->parent->right->right))
			{
				free_queue(queue);
				return (0);
			}
			push_to_queue(&queue, current->left);
		}
		else if (!current->left && current->right)
		{
			free_queue(queue);
			return (0);
		}
		remove_from_queue(&queue);
	}

	free(queue);
	return (1);
}
