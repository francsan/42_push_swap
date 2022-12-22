/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:49:37 by francisco         #+#    #+#             */
/*   Updated: 2022/12/22 17:06:14 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_valid(char **argv)
{
	int	i;

	i = -1;
	while (argv[1][++i])
	{
		if ((argv[1][i] == '+' || argv[1][i] == '-') && i == 0)
			i++;
		if (argv[1][i] < '0' || argv[1][i] > '9')
			error_msg(ERR);
	}
	ft_atoi(argv[1]);
}

void	error_msg(char *error)
{
	write(2, error, ft_strlen(error));
	exit(1);
}
