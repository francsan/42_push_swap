/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:47:56 by francisco         #+#    #+#             */
/*   Updated: 2022/11/27 20:14:40 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_node **tail)
{
	if ((*tail)->n > (*tail)->next->n)
		swap(tail, 'a');
}

void	sort_3(t_node **tail, t_node **head)
{
	t_node	*curr;
	int		i;

	curr = (*tail);
	i = 1;
	while (i < 3)
	{
		if (i == 1 && curr->n > curr->next->n && curr->n > curr->next->next->n)
			rotate(tail, 'a');
		if (i == 1 && curr->n < curr->next->n && curr->n > curr->next->next->n)
			r_rotate(head, 'a');
		if (curr->n > curr->next->n)
		{
			if (i == 1)
				swap(tail, 'a');
			if (i == 2)
			{
				rotate(tail, 'a');
				swap(tail, 'a');
				r_rotate(head, 'a');
			}
		}
		curr = curr->next;
		i++;
	}
}

int	check_order(t_node **tail)
{
	t_node	*curr;

	curr = *tail;
	while (curr->next != NULL)
	{
		if (!(curr->n < curr->next->n))
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	sorting(t_node **tail_a, t_node **head_a, int argc)
{
	t_node	*tail_b;
	t_node	*head_b;

	tail_b = NULL;
	head_b = NULL;
	while (!check_order(tail_a))
	{
		if (argc == 3)
			sort_2(tail_a);
		if (argc == 4)
			sort_3(tail_a, head_a);
	}
	free_list(&tail_b, &head_b);
}
