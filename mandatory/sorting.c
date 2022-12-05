/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:47:56 by francisco         #+#    #+#             */
/*   Updated: 2022/12/05 17:49:33 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_data *d, char stack)
{
	if (stack == 'a')
	{
		if ((d->tail_a)->n > (d->tail_a)->next->n)
			swap(&(d->tail_a), 'a');
	}
	if (stack == 'b')
	{
		if ((d->tail_b)->n < (d->tail_b)->next->n)
			swap(&(d->tail_b), 'b');
	}
}

void	sort_3(t_data *d)
{
	if ((d->tail_a)->n < (d->tail_a)->next->next->n)
	{
		if ((d->tail_a)->next->n > (d->tail_a)->next->next->n)
		{
			r_rotate(&(d->head_a), 'a');
			swap(&(d->tail_a), 'a');
		}
		else if ((d->tail_a)->next->n < (d->tail_a)->next->next->n)
			swap(&(d->tail_a), 'a');
	}
	else if ((d->tail_a)->n > (d->tail_a)->next->next->n)
	{
		if ((d->tail_a)->n < (d->tail_a)->next->n)
			r_rotate(&(d->head_a), 'a');
		else if ((d->tail_a)->next->n < (d->tail_a)->next->next->n)
			rotate(&(d->tail_a), 'a');
		else if ((d->tail_a)->next->n > (d->tail_a)->next->next->n)
		{
			swap(&(d->tail_a), 'a');
			r_rotate(&(d->head_a), 'a');
		}
	}
}

void	sort_4(t_data *d)
{
	get_limits(d);
	get_order(d);
	while (!d->tail_b)
	{
		if ((d->tail_a)->order == 0)
		{
			push(&(d->tail_a), &(d->tail_b), &(d->head_b), 'b');
			break ;
		}
		else
			rotate(&(d->tail_a), 'a');
	}
	sort_3(d);
	push(&(d->tail_b), &(d->tail_a), &(d->head_a), 'a');
}

void	sort_5(t_data *d)
{
	int	i;

	get_limits(d);
	get_order(d);
	i = 0;
	while (i < 2)
	{
		if ((d->tail_a)->order == 0 || (d->tail_a)->order == 1)
		{
			push(&(d->tail_a), &(d->tail_b), &(d->head_b), 'b');
			i++;
		}
		else
			rotate(&(d->tail_a), 'a');
	}
	sort_3(d);
	sort_2(d, 'b');
	while (d->tail_b)
		push(&(d->tail_b), &(d->tail_a), &(d->head_a), 'a');
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
	if (!check_order(d))
	{
		if (argc == 3)
			sort_2(d, 'a');
		else if (argc == 4)
			sort_3(d);
		else if (argc == 5)
			sort_4(d);
		else if (argc == 6)
			sort_5(d);
		else if (argc > 6)
			radix_sort(d);
	}
	if (d->tail_b)
		free_list(&(d->tail_b), &(d->head_b));
}
