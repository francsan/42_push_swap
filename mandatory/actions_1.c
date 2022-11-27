/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:59:09 by francisco         #+#    #+#             */
/*   Updated: 2022/11/27 20:04:17 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_node **tail, char stack)
{
	int	n;

	n = (*tail)->n;
	(*tail)->n = (*tail)->next->n;
	(*tail)->next->n = n;
	if (stack == 'a')
		write(1, "sa\n", 3);
	if (stack == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_node **tail, char stack)
{
	t_node	*curr;
	int		n;

	curr = *tail;
	n = (*tail)->n;
	while (curr->next != NULL)
	{
		curr->n = curr->next->n;
		curr = curr->next;
	}
	curr->n = n;
	if (stack == 'a')
		write(1, "ra\n", 3);
	if (stack == 'b')
		write(1, "rb\n", 3);
}

void	r_rotate(t_node **head, char stack)
{
	t_node	*curr;
	int		n;

	curr = *head;
	n = curr->n;
	while (curr->prev != NULL)
	{
		curr->n = curr->prev->n;
		curr = curr->prev;
	}
	curr->n = n;
	if (stack == 'a')
		write(1, "rra\n", 4);
	if (stack == 'b')
		write(1, "rrb\n", 4);
}

void	push(t_node **t_from, t_node **t_to, t_node **h_to, char stack)
{
	t_node	*temp;

	if (!(*t_to))
		init(t_to, h_to, (*t_from)->n);
	else
		add_node_tail(t_to, (*t_from)->n);
	temp = (*t_from)->next;
	remove_node(*t_from);
	*t_from = temp;
	if (stack == 'a')
		write(1, "pa\n", 3);
	if (stack == 'b')
		write(1, "pb\n", 3);
}
