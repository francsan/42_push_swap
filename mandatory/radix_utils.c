/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:49:49 by francisco         #+#    #+#             */
/*   Updated: 2022/12/22 15:49:41 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_order(t_data *d)
{
	t_node	*curr;

	curr = d->tail_a;
	while (curr->next != NULL)
	{
		if (!(curr->n < curr->next->n))
			return (0);
		curr = curr->next;
	}
	return (1);
}

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

void	get_next_num(t_data *d)
{
	t_node	*curr;
	int		next;

	curr = d->tail_a;
	next = d->max;
	while (curr != NULL)
	{
		if (curr->n < next && curr->n > d->num)
			next = curr->n;
		curr = curr->next;
	}
	d->num = next;
}

void	get_order(t_data *d)
{
	t_node	*curr;
	int		order;

	d->num = d->min;
	order = 0;
	while (d->num <= d->max)
	{
		curr = d->tail_a;
		while (curr != NULL)
		{
			if (curr->n == d->num)
			{
				curr->order = order;
				order++;
				break ;
			}
			curr = curr->next;
		}
		if (d->num == d->max)
			break ;
		get_next_num(d);
	}
	d->size = order;
	d->size_a = d->size;
	d->size_b = 0;
}
