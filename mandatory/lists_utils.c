/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:59:42 by francisco         #+#    #+#             */
/*   Updated: 2022/11/25 23:04:02 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list(t_node **tail, t_node **head)
{
	t_node	*curr;

	if (*tail == NULL)
		return ;
	curr = *tail;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	*tail = NULL;
	*head = NULL;
}

void	remove_node(t_node *node)
{
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	free(node);
}

void	add_node_tail(t_node **tail, int n)
{
	t_node	*new_node;

	new_node = ft_calloc(sizeof(t_node), 1);
	if (!new_node)
		error_msg(ERR);
	new_node->n = n;
	new_node->next = *tail;
	new_node->prev = NULL;
	(*tail)->prev = new_node;
	*tail = new_node;
}

void	add_node_head(t_node **head, int n)
{
	t_node	*new_node;

	new_node = ft_calloc(sizeof(t_node), 1);
	if (!new_node)
		error_msg(ERR);
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = *head;
	(*head)->next = new_node;
	*head = new_node;
}

void	init(t_node **tail, t_node **head, int n)
{
	t_node	*new_node;

	new_node = ft_calloc(sizeof(t_node), 1);
	if (!new_node)
		error_msg(ERR);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	*tail = new_node;
	*head = new_node;
}
