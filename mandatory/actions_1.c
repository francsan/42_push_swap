/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:59:09 by francisco         #+#    #+#             */
/*   Updated: 2022/12/03 18:25:47 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_node **tail, char stack)
{
	int	n;
	int	order;

	n = (*tail)->n;
	order = (*tail)->order;
	(*tail)->n = (*tail)->next->n;
	(*tail)->order = (*tail)->next->order;
	(*tail)->next->n = n;
	(*tail)->next->order = order;
	if (stack == 'a')
		write(1, "sa\n", 3);
	if (stack == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_node **tail, char stack)
{
	t_node	*curr;
	int		n;
	int		order;

	curr = *tail;
	n = (*tail)->n;
	order = (*tail)->order;
	while (curr->next != NULL)
	{
		curr->n = curr->next->n;
		curr->order = curr->next->order;
		curr = curr->next;
	}
	curr->n = n;
	curr->order = order;
	if (stack == 'a')
		write(1, "ra\n", 3);
	if (stack == 'b')
		write(1, "rb\n", 3);
}

void	r_rotate(t_node **head, char stack)
{
	t_node	*curr;
	int		n;
	int		order;

	curr = *head;
	n = curr->n;
	order = curr->order;
	while (curr->prev != NULL)
	{
		curr->n = curr->prev->n;
		curr->order = curr->prev->order;
		curr = curr->prev;
	}
	curr->n = n;
	curr->order = order;
	if (stack == 'a')
		write(1, "rra\n", 4);
	if (stack == 'b')
		write(1, "rrb\n", 4);
}

void	push(t_node **t_from, t_node **t_to, t_node **h_to, char stack)
{
	t_node	*temp;

	if (!(*t_to))
		init_list(t_to, h_to, (*t_from)->n, (*t_from)->order);
	else
		add_node_tail(t_to, (*t_from)->n, (*t_from)->order);
	temp = (*t_from)->next;
	remove_node(*t_from);
	*t_from = temp;
	if (stack == 'a')
		write(1, "pa\n", 3);
	if (stack == 'b')
		write(1, "pb\n", 3);
}
