/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:51:36 by francisco         #+#    #+#             */
/*   Updated: 2022/11/28 03:47:12 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// for read, write 
# include <unistd.h>
// for malloc, free, exit
# include <stdlib.h>
// for TESTING
# include <stdio.h>
# include <string.h>

/* structs */

// double linked list
typedef struct t_node {
	int				n;
	struct t_node	*next;
	struct t_node	*prev;
}	t_node;

// data struct
typedef struct t_data {
	int				size_a;
	int				size_b;
	int				max;
	int				place;
	struct t_node	*tail_a;
	struct t_node	*head_a;
	struct t_node	*tail_b;
	struct t_node	*head_b;
}	t_data;

/* errors */

# define ERR "Error\n"

/* push_swap functions */

// fill_stack_a.c
int		check_num(t_data *d, int n);
void	fill_stack_a(t_data *d, char **argv);

// actions_1.c
void	swap(t_node **tail, char stack);
void	rotate(t_node **tail, char stack);
void	r_rotate(t_node **head, char stack);
void	push(t_node **t_from, t_node **t_to, t_node **h_to, char stack);

// actions_2.c
void	swap_both(t_node **tail_a, t_node **tail_b);
void	rotate_both(t_node **tail_a, t_node **tail_b);
void	r_rotate_both(t_node **head_a, t_node **head_b);

// sorting.c
void	sort_2(t_data *d);
void	sort_3(t_data *d);
int		check_order(t_data *d);
void	sorting(t_data *d, int argc);

// radix.c
void	get_max(t_data *d);
void	sort_all(t_data *d);
void	radix_sort(t_data *d, int argc);

// lists_utils.c
void	free_list(t_node **tail, t_node **head);
void	remove_node(t_node *node);
void	add_node_tail(t_node **tail, int n);
void	add_node_head(t_node **head, int n);
void	init(t_node **tail, t_node **head, int n);

// errors.c
void	error_msg(char *error);

/* libft functions */

// ft_atoi.c
int		ft_atoi(const char *str);

// ft_calloc.c
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

// ft_strlen.c
size_t	ft_strlen(const char *s);

#endif
