/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:21:42 by francisco         #+#    #+#             */
/*   Updated: 2022/12/03 18:32:56 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_a_to_b(t_data *d, t_sorting *s)
{
	s->digit = 0;
	s->i = 0;
	while (s->digit <= 9)
	{
		while (s->i < d->size_a)
		{
			s->temp = ((d->tail_a)->order / d->place);
			s->temp %= 10;
			if (s->digit == s->temp)
			{
				push(&(d->tail_a), &(d->tail_b), &(d->head_b), 'b');
				d->size_a--;
				d->size_b++;
			}
			else
			{
				rotate(&(d->tail_a), 'a');
				s->i++;
			}
		}
		s->digit++;
		s->i = 0;
	}
}

void	sort_b_to_a(t_data *d, t_sorting *s)
{
	s->digit = 9;
	s->i = 0;
	while (s->digit >= 0)
	{
		while (s->i < d->size_b)
		{
			s->temp = ((d->tail_b)->order / d->place);
			s->temp %= 10;
			if (s->digit == s->temp)
			{
				push(&(d->tail_b), &(d->tail_a), &(d->head_a), 'a');
				d->size_a++;
				d->size_b--;
			}
			else
			{
				rotate(&(d->tail_b), 'b');
				s->i++;
			}
		}
		s->digit--;
		s->i = 0;
	}
}

void	radix_sort(t_data *d)
{
	t_sorting	*s;

	get_limits(d);
	get_order(d);
	d->place = 1;
	while ((d->size - 1) / d->place > 0)
	{
		s = ft_calloc(sizeof(t_sorting), 1);
		if (d->size_a != 0)
			sort_a_to_b(d, s);
		else if (d->size_b != 0)
			sort_b_to_a(d, s);
		free(s);
		d->place *= 10;
	}
	while (d->tail_b)
		push(&(d->tail_b), &(d->tail_a), &(d->head_a), 'a');
}
