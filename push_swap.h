/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:59:44 by jsanger           #+#    #+#             */
/*   Updated: 2023/08/25 09:41:01 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}				t_list;

struct arr_5
{
	int	pos[5];
	int	val[5];
};

void	add_end(t_list **root, int x);
void	add_front(t_list **root, int x);
void	deallocate(t_list **root);

int		is_sorted(t_list **stack);
int		find_max_val(t_list **stack);
int		find_min(t_list *root);

t_list	*copy_lst(t_list *root);
t_list	*simplify_list(t_list *root);
void	simplify_values(t_list* root, int* values, int size);
void	sort_values(int* values, int size);
int		get_size(t_list *root);

void radix_sort(t_list** stack_a, t_list** stack_b, int bit);
void		sort_list(t_list** stack_a, t_list** stack_b);


void	error(int error, t_list **stack_a, t_list **stack_b);
void	check_wrong_input(char *str, t_list **s_a, t_list **s_b);
void	check_dopples(t_list **stack_a,t_list **stack_b, int check);
void	deallocate_ab(t_list **stack_a, t_list **stack_b);


void	less_three(t_list **stack);
void	less_five(t_list **stack_a, t_list **stack_b);



void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif
