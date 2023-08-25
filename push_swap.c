/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:58:18 by jsanger           #+#    #+#             */
/*   Updated: 2023/08/25 17:07:07 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list(t_list **stack_a, int bit)
{
	t_list	*curr;

	curr = *stack_a;
	while (curr->next != NULL)
	{
		if (((curr->value >> bit) & 1) == 0)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void print_a_b(t_list **stack_a, t_list **stack_b)
{
	printf("Stack_a:\n");
	for (t_list *curr = *stack_a; curr != NULL; curr = curr->next)
		printf("%d\n", curr->value);
	printf("Stack_b:\n");
	for (t_list *curr = *stack_b; curr != NULL; curr = curr->next)
		printf("%d\n", curr->value);
}

void	insert_stack_a(t_list **stack_a, t_list **stack_b, int argc, char **argv)
{
	int	i;
	if (argc < 2)
	{
		printf("No Input\n");
		exit(1);
	}
	i = 0;
	while (++i < argc)
	{
		check_wrong_input(argv[i], stack_a, stack_b);
		check_dopples(stack_a, stack_b, atoi(argv[i]));
		add_end(stack_a, atoi(argv[i]));
	}
}

void radix_sort(t_list** stack_a, t_list** stack_b, int bit)
{
	int	i = -1;
	int	len = get_size(*stack_a);
	while (i < len) // (check_list(stack_a, bit))
	{
		if (is_sorted(stack_a) == 0)
			break ;
		if ((((*stack_a)->value >> bit) & 1) == 0)
		{
			pb(stack_a, stack_b);
			printf("pb\n");
		}
		else
		{
			ra(stack_a);
			printf("ra\n");
		}
		i++;
	}
	while ((*stack_b) != NULL)
	{
		pa(stack_a, stack_b);
		printf("pa\n");
	}
}

void sort_list(t_list** stack_a, t_list** stack_b)
{
	int i;

	i = 0;
	if (is_sorted(stack_a) == 0)
		return;
	while (i < 31)
	{
		radix_sort(stack_a, stack_b, i);
		if (is_sorted(stack_a) == 0)
			return;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	insert_stack_a(&stack_a, &stack_b, argc, argv);
	stack_a = simplify_list(stack_a);

	sort_list(&stack_a, &stack_b);


	print_a_b(&stack_a, &stack_b);
	deallocate_ab(&stack_a, &stack_b);
	return 0;
}

