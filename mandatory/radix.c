/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:21:42 by francisco         #+#    #+#             */
/*   Updated: 2022/12/02 11:21:33 by francisco        ###   ########.fr       */
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

void	sort_all(t_data *d)
{
	int	digit;
	int	temp;
	int	i;

	digit = 0;
	i = 0;
	if (d->size_a != 0)
	{
		while (digit <= 9)
		{
			while (i < d->size_a)
			{
				temp = ((d->tail_a)->order / d->place);
				temp %= 10;
				if (digit == temp)
				{
					push(&(d->tail_a), &(d->tail_b), &(d->head_b), 'b');
					if ((d->tail_b)->next)
						rotate(&(d->tail_b), 'b');
					d->size_a--;
					d->size_b++;
				}
				else
				{
					rotate(&(d->tail_a), 'a');
					i++;
				}
			}
			digit++;
			i = 0;
		}
	}
	else if (d->size_b != 0)
	{
		while (digit <= 9)
		{
			while (i < d->size_b)
			{
				temp = ((d->tail_b)->order / d->place);
				temp %= 10;
				if (digit == temp)
				{
					push(&(d->tail_b), &(d->tail_a), &(d->head_a), 'a');
					if ((d->tail_a)->next)
						rotate(&(d->tail_a), 'a');
					d->size_a++;
					d->size_b--;
				}
				else
				{
					rotate(&(d->tail_b), 'b');
					i++;
				}
			}
			digit++;
			i = 0;
		}
	}
}

void	radix_sort(t_data *d)
{
	get_limits(d);
	get_order(d);
	d->place = 1;
	while ((d->size - 1) / d->place > 0)
	{
		sort_all(d);
		d->place *= 10;
	}
	while (d->tail_b != NULL)
	{
		push(&(d->tail_b), &(d->tail_a), &(d->head_a), 'a');
		if ((d->tail_a)->next)
			rotate(&(d->tail_a), 'a');
	}
}
