/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:21:45 by francisco         #+#    #+#             */
/*   Updated: 2022/11/25 23:01:21 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_both(t_node **tail_a, t_node **tail_b)
{
	swap(tail_a, 0);
	swap(tail_b, 0);
	write(1, "ss\n", 3);
}

void	rotate_both(t_node **tail_a, t_node **tail_b)
{
	rotate(tail_a, 0);
	rotate(tail_b, 0);
	write(1, "rr\n", 3);
}

void	r_rotate_both(t_node **head_a, t_node **head_b)
{
	r_rotate(head_a, 0);
	r_rotate(head_b, 0);
	write(1, "rrr\n", 4);
}

void	push(t_node **tail_a, t_node **tail_b, char stack)
{
	t_node	*temp;

	if (stack == 'a')
	{
		add_node_tail(tail_a, (*tail_b)->n);
		temp = (*tail_b)->next;
		remove_node(*tail_b);
		*tail_b = temp;
		write(1, "pa\n", 3);
	}
	if (stack == 'b')
	{
		if ((*tail_b)->n == 0 && (*tail_b)->next == NULL
			&& (*tail_a)->n != 0)
			(*tail_b)->n = (*tail_a)->n;
		else
			add_node_tail(tail_b, (*tail_a)->n);
		temp = (*tail_a)->next;
		remove_node(*tail_a);
		*tail_a = temp;
		write(1, "pb\n", 3);
	}
}