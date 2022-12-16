/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:14:59 by francisco         #+#    #+#             */
/*   Updated: 2022/12/16 19:59:41 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	if (argc <= 2)
	{
		ft_atoi(argv[1]);
		return (0);
	}
	d = ft_calloc(sizeof(t_data), 1);
	if (!d)
		error_msg(ERR);
	fill_stack(d, argv);
	sorting(d, argc);
	free_list(&(d->tail_a), &(d->head_a));
	free(d);
	return (0);
}
