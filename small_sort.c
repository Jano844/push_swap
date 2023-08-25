/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:16:17 by jsanger           #+#    #+#             */
/*   Updated: 2023/08/09 21:59:59 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	less_three(t_list **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
	if (is_sorted(stack) == 1)
	{
		if ((*stack)->value > (*stack)->next->next->value)
			rra(stack);
		else
		{
			sa(stack);
			ra(stack);
		}
	}
}

void	less_five(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->value != find_max_val(stack_a))
		ra(stack_a);
	pb(stack_a, stack_b);
	while ((*stack_a)->value != find_max_val(stack_a))
		ra(stack_a);
	pb(stack_a, stack_b);
	less_three(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
}
