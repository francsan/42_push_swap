/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:21:45 by francisco         #+#    #+#             */
/*   Updated: 2022/12/22 15:49:27 by francsan         ###   ########.fr       */
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
