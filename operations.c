/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:17:51 by jsanger           #+#    #+#             */
/*   Updated: 2023/08/23 00:52:22 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	t_list *second = (*stack_a)->next;
	(*stack_a)->next = (*stack_a)->next->next;
	second->next = *stack_a;
	(*stack_a) = second;
}

void	sb(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	t_list *second = (*stack_b)->next;
	(*stack_b)->next = (*stack_b)->next->next;
	second->next = *stack_b;
	(*stack_b) = second;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b == NULL)
		return ;
	add_front(stack_a, (*stack_b)->value);
	t_list *temp = *stack_b;
	*stack_b = (*stack_b)->next;
	free(temp);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL)
		return ;
	add_front(stack_b, (*stack_a)->value);
	t_list *temp = *stack_a;
	*stack_a = (*stack_a)->next;
	free(temp);
}

void	ra(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	t_list *curr = *stack_a;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = *stack_a;
	*stack_a = (*stack_a)->next;
	curr->next->next = NULL;
}

void	rb(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	t_list *curr = *stack_b;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = *stack_b;
	*stack_b = (*stack_b)->next;
	curr->next->next = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	t_list *curr = *stack_a;
	while (curr->next->next != NULL) {
		curr = curr->next;
	}
	t_list *lastNode = curr->next;
	curr->next = NULL;
	lastNode->next = *stack_a;
	*stack_a = lastNode;
}

void	rrb(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	t_list *curr = *stack_b;
	while (curr->next->next != NULL) {
		curr = curr->next;
	}
	t_list *lastNode = curr->next;
	curr->next = NULL;
	lastNode->next = *stack_b;
	*stack_b = lastNode;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
