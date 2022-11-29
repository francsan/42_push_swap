/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:47:56 by francisco         #+#    #+#             */
/*   Updated: 2022/11/29 00:11:22 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_data *d)
{
	if ((d->tail_a)->n > (d->tail_a)->next->n)
		swap(&(d->tail_a), 'a');
}

void	sort_3(t_data *d)
{
	t_node	*curr;
	int		i;

	curr = (d->tail_a);
	i = 1;
	while (i < 3)
	{
		if (i == 1 && curr->n > curr->next->n && curr->n > curr->next->next->n)
			rotate(&(d->tail_a), 'a');
		if (i == 1 && curr->n < curr->next->n && curr->n > curr->next->next->n)
			r_rotate(&(d->head_a), 'a');
		if (curr->n > curr->next->n)
		{
			if (i == 1)
				swap(&(d->tail_a), 'a');
			if (i == 2)
			{
				rotate(&(d->tail_a), 'a');
				swap(&(d->tail_a), 'a');
				r_rotate(&(d->head_a), 'a');
			}
		}
		curr = curr->next;
		i++;
	}
}

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

void	sorting(t_data *d, int argc)
{
	d->tail_b = NULL;
	d->head_b = NULL;
	if (!check_order(d))
	{
		if (argc == 3)
			sort_2(d);
		if (argc == 4)
			sort_3(d);
		if (argc > 4)
			radix_sort(d);
	}
	free_list(&(d->tail_b), &(d->head_b));
}
