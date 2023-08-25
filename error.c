/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 07:59:23 by jsanger           #+#    #+#             */
/*   Updated: 2023/08/25 10:41:18 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int error, t_list **stack_a, t_list **stack_b)
{
	printf("Error, ");
	if (error == 1)
		printf("Malloc\n");
	if (error == 2)
		printf("Wrong Input\n");
	if (error == 3)
		printf("Dopples In Input\n");
	deallocate_ab(stack_a, stack_b);
	exit(1);
}

void	check_wrong_input(char *str, t_list **s_a, t_list **s_b)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		error(2, s_a, s_b);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			error(2, s_a, s_b);
		i++;
	}
}

void	check_dopples(t_list **stack_a,t_list **stack_b, int check)
{
	t_list	*curr;

	curr = *stack_a;
	while (curr != NULL)
	{
		if (curr->value == check)
			error(3, stack_a, stack_b);
		curr = curr->next;
	}
}

void	deallocate_ab(t_list **stack_a, t_list **stack_b)
{
	deallocate(stack_a);
	deallocate(stack_b);
}
