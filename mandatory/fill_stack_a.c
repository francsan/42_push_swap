/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:14:02 by francisco         #+#    #+#             */
/*   Updated: 2022/11/25 23:03:52 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_num(t_node **head, int n)
{
	t_node	*curr;

	curr = (*head)->prev;
	while (curr != NULL)
	{
		if (n == curr->n)
			return (1);
		curr = curr->prev;
	}
	return (0);
}

void	fill_stack_a(t_node **tail, t_node **head, char **argv)
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
			if (argv[i][j] < '0' || argv[i][j] > '9')
				error_msg(ERR);
		}
	}
	i = 1;
	init(tail, head, ft_atoi(argv[i]));
	while (argv[++i])
	{
		add_node_head(head, ft_atoi(argv[i]));
		if (check_num(head, ft_atoi(argv[i])))
			error_msg(ERR);
	}
}
