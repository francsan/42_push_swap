/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:21:42 by francisco         #+#    #+#             */
/*   Updated: 2022/11/28 17:51:02 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_max(t_data *d)
{
	t_node	*curr;
	int		n;

	curr = d->tail_a;
	d->max = curr->n;
	while (curr != NULL)
	{
		if (curr->n == -2147483648)
			n = 2147483647;
		else if (curr->n < 0)
			n = -1 * curr->n;
		else
			n = curr->n;
		if (n > d->max)
			d->max = curr->n;
		curr = curr->next;
	}
}

void	sort_all(t_data *d)
{
	int	temp1;
	int	temp2;
	int	i;

	temp1 = 0;
	i = 0;
	if (d->tail_a)
	{
		while (temp1 <= 9)
		{
			while (i < d->size_a)
			{
				temp2 = (((d->tail_a)->n % d->place) / (d->place / 10));
				if (temp1 == temp2)
				{
					push(&(d->tail_a), &(d->tail_b), &(d->head_b), 'b');
					(d->size_a)--;
					(d->size_b)++;
					i = 0;
				}
				else
					rotate(&(d->tail_a), 'a');
				i++;
			}
			temp1++;
			i = 0;
		}
	}
	if (d->tail_b)
	{
		while (temp1 <= 9)
		{
			while (i < d->size_b)
			{
				temp2 = (((d->tail_b)->n % d->place) / (d->place / 10));
				if (temp1 == temp2)
				{
					push(&(d->tail_b), &(d->tail_a), &(d->head_a), 'a');
					if ((d->tail_a)->next)
						rotate(&(d->tail_a), 'a');
					(d->size_a)++;
					(d->size_b)--;
					i = 0;
				}
				else
					rotate(&(d->tail_b), 'a');
				i++;
			}
			temp1++;
			i = 0;
		}
	}
}

void	radix_sort(t_data *d, int argc)
{
	int	i;

	d->size_a = argc - 1;
	d->size_b = 0;
	get_max(d);
	d->place = 1;
	while (d->max / d->place > 0)
	{
		d->place *= 10;
		sort_all(d);
	}
	i = 0;
	if (d->tail_b)
	{
		while (i < d->size_b)
		{
			push(&(d->tail_b), &(d->tail_a), &(d->head_a), 'a');
			i++;
		}
	}
}
