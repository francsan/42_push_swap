/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:14:59 by francisco         #+#    #+#             */
/*   Updated: 2022/11/28 17:55:19 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	if (argc < 2)
		return (0);
	d = ft_calloc(sizeof(t_data), 1);
	fill_stack_a(d, argv);
	// printf ("\e[1;33mStack A - Initial\n\e[0m");
	// t_node	*curr = d->tail_a;
	// while (curr != NULL)
	// {
	// 	printf("%d\n", curr->n);
	// 	curr = curr->next;
	// }
	// printf ("\e[1;34mActions\n\e[0m");
	sorting(d, argc);
	// curr = d->tail_a;
	// printf ("\e[1;32mStack A - Final\n\e[0m");
	// while (curr != NULL)
	// {
	// 	printf("%d\n", curr->n);
	// 	curr = curr->next;
	// }
	free_list(&(d->tail_a), &(d->head_a));
	free(d);
}
