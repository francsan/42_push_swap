/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:21:42 by francisco         #+#    #+#             */
/*   Updated: 2022/11/29 02:22:42 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_limits(t_data *d)
{
	t_node	*curr;

	curr = d->tail_a;
	d->min = curr->n;
	while (curr->next != NULL)
	{
		if (curr->next->n < d->min)
			d->min = curr->next->n;
		curr = curr->next;
	}
	curr = d->tail_a;
	d->max = curr->n;
	while (curr->next != NULL)
	{
		if (curr->next->n > d->max)
			d->max = curr->next->n;
		curr = curr->next;
	}
}

void	get_order(t_data *d)
{
	t_node	*curr;
	int		n;
	int		order;

	curr = d->tail_a;
	n = d->min;
	order = 0;
	while (n <= d->max)
	{
		while (curr != NULL)
		{
			if (curr->n == n)
			{
				curr->order = order;
				order++;
				break ;
			}
			curr = curr->next;
		}
		n++;
		curr = d->tail_a;
	}
	d->size = order;
	d->size_a = d->size;
	d->size_b = 0;
}

void	radix_sort(t_data *d)
{
	int	order;
	int	n_order;

	get_limits(d);
	get_order(d);
	order = 0;
	while (order < d->size - 1)
	{
		n_order = (d->tail_a)->order;
		if (order == n_order)
		{
			push(&(d->tail_a), &(d->tail_b), &(d->head_b), 'b');
			order++;
		}
		else
			rotate(&(d->tail_a), 'a');
	}
	while (d->tail_b)
		push(&(d->tail_b), &(d->tail_a), &(d->head_a), 'a');
}
