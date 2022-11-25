/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:14:59 by francisco         #+#    #+#             */
/*   Updated: 2022/11/25 23:03:42 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting(t_node **tail_a)
{
	t_node	*tail_b;
	t_node	*head_b;

	init(&tail_b, &head_b, 0);
	push(tail_a, &tail_b, 'b');
	push(tail_a, &tail_b, 'b');
	t_node	*curr = tail_b;
	printf("Stack B\n");
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
	push(tail_a, &tail_b, 'a');
	push(tail_a, &tail_b, 'a');
	push(tail_a, &tail_b, 'b');
	curr = tail_b;
	printf("Stack B\n");
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
	free_list(&tail_b, &head_b);
}

int	main(int argc, char **argv)
{
	t_node	*tail;
	t_node	*head;

	if (argc < 2)
		error_msg(ERR);
	fill_stack_a(&tail, &head, argv);
	sorting(&tail);
	t_node	*curr = tail;
	printf("Stack A\n");
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
	free_list(&tail, &head);
}
