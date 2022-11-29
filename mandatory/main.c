/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:14:59 by francisco         #+#    #+#             */
/*   Updated: 2022/11/29 02:53:12 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	if (argc < 2)
		return (0);
	d = ft_calloc(sizeof(t_data), 1);
	if (!d)
		error_msg(ERR);
	fill_stack_a(d, argv);
	sorting(d, argc);
	free_list(&(d->tail_a), &(d->head_a));
	free(d);
}
