/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:54:58 by jsanger           #+#    #+#             */
/*   Updated: 2023/08/23 00:05:45 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list *curr;

	curr = *stack;
	while (curr->next != NULL)
	{
		if (curr->value > curr->next->value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	find_max_val(t_list **stack)
{
	t_list	*curr;
	int		max;

	curr = *stack;
	max = 0;
	while (curr != NULL)
	{
		if (max < curr->value)
			max = curr->value;
		curr = curr->next;
	}
	return (max);
}

// // // // int	find_min_val(t_list **stack, int last_min)
// // // // {
// // // // 	t_list	*curr;
// // // // 	int		min;
// // // // 	int		i;

// // // // 	curr = *stack;
// // // // 	min = 2147483647;
// // // // 	while (curr != NULL)
// // // // 	{
// // // // 		if (min > curr->value && curr->value > last_min)
// // // // 			min = curr->value;
// // // // 		curr = curr->next;
// // // // 	}
// // // // 	curr = *stack;
// // // // 	i = 1;
// // // // 	while (curr != NULL)
// // // // 	{
// // // // 		if (min == curr->value)
// // // // 			return (i);
// // // // 		curr = curr->next;
// // // // 		i++;
// // // // 	}
// // // // 	return (i);
// // // // }

// // // // struct arr_5 smallest_five(t_list **stack_a, t_list **stack_b)
// // // // {
// // // // 	struct	arr_5 pos_val;
// // // // 	int		position = 0;
// // // // 	int		controll;
// // // // 	int		i = 0;

// // // // 	controll = 0;
// // // // 	for(t_list	*curr = *stack_a; curr != NULL; curr = curr->next)
// // // // 	{
// // // // 		for(t_list	*temp = *stack_a; temp != NULL; temp = temp->next)
// // // // 		{
// // // // 			if (curr->value > temp->value)
// // // // 				controll++;
// // // // 		}
// // // // 		if (controll < 5)
// // // // 		{
// // // // 			pos_val.pos[i] = position;
// // // // 			pos_val.val[i] = curr->value;
// // // // 			i++;
// // // // 		}
// // // // 		controll = 0;
// // // // 		position++;
// // // // 	}
// // // // 	return (pos_val);
// // // // }
