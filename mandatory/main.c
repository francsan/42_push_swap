/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:14:59 by francisco         #+#    #+#             */
/*   Updated: 2022/11/27 20:11:43 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*tail;
	t_node	*head;

	if (argc < 2)
		error_msg(ERR);
	fill_stack_a(&tail, &head, argv);
	printf ("\e[1;33mStack A - Initial\n\e[0m");
	t_node	*curr = tail;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
	printf ("\e[1;34mActions\n\e[0m");
	sorting(&tail, &head, argc);
	curr = tail;
	printf ("\e[1;32mStack A - Final\n\e[0m");
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
	free_list(&tail, &head);
}
