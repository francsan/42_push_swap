/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:41:09 by francsan          #+#    #+#             */
/*   Updated: 2022/12/16 01:33:48 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_data *d)
{
	int	bit_counter;
	int	stored_n;

	bit_counter = 0;
	while (!check_order(d) && bit_counter <= d->bit_max)
	{
		stored_n = -1;
		while ((d->tail_a)->order != stored_n)
		{
			if (!(d->tail_a->order >> bit_counter & 1))
				push(&(d->tail_a), &(d->tail_b), &(d->head_b), 'b');
			else
			{
				if (stored_n == -1)
					stored_n = d->tail_a->order;
				rotate(&(d->tail_a), 'a');
			}
		}
		while (d->tail_b)
			push(&(d->tail_b), &(d->tail_a), &(d->head_a), 'a');
		bit_counter++;
	}
}

void	get_bit_max(t_data *d)
{
	int	order_max;

	order_max = d->size - 1;
	d->bit_max = 0;
	while (order_max > 0)
	{
		d->bit_max++;
		order_max = order_max >> 1;
	}
}

void	sort_all(t_data *d)
{
	get_limits(d);
	get_order(d);
	get_bit_max(d);
	radix_sort(d);
}
