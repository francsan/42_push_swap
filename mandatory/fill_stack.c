/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:14:02 by francisco         #+#    #+#             */
/*   Updated: 2022/12/22 15:49:33 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_num(t_data *d, int n)
{
	t_node	*curr;

	curr = (d->head_a)->prev;
	while (curr != NULL)
	{
		if (n == curr->n)
			return (1);
		curr = curr->prev;
	}
	return (0);
}

void	fill_stack(t_data *d, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				error_msg(ERR);
		}
	}
	i = 1;
	init_list(&(d->tail_a), &(d->head_a), ft_atoi(argv[i]), 0);
	while (argv[++i])
	{
		add_node_head(&(d->head_a), ft_atoi(argv[i]), 0);
		if (check_num(d, ft_atoi(argv[i])))
			error_msg(ERR);
	}
}
