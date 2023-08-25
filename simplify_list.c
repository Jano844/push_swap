/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:03:48 by jsanger           #+#    #+#             */
/*   Updated: 2023/08/22 15:04:10 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function to find the minimum value in the list

#include "push_swap.h"

int	find_min(t_list *root)
{
	int		min;
	t_list	*current;

	min = root->value;
	current = root->next;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

t_list	*copy_lst(t_list *root)
{
	t_list	*copy;
	t_list	*curr;

	copy = NULL;
	curr = root;
	while (curr != NULL)
	{
		add_end(&copy, curr->value);
		curr = curr->next;
	}
	return (copy);
}

// sorts array
void sort_values(int *values, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[j] < values[i])
			{
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
			j++;
		}
		i++;
	}
}

// Function to assign position of sorted array to copy
void simplify_values(t_list *root, int *values, int size)
{
	t_list	*current;
	int		original_value;
	int		i;

	current = root;
	while (current != NULL)
	{
		original_value = current->value;
		i = 0;
		while (i < size)
		{
			if (values[i] == original_value)
			{
				current->value = i;
				break;
			}
			i++;
		}
		current = current->next;
	}
}
// creates a copy of stack_a, creates an array like stack_a,
// sorts the array, values in copy are become the position in array
t_list* simplify_list(t_list* root)
{
	int		*values;
	int		i;
	int		size;
	t_list*	copy;
	t_list*	current;

	copy = copy_lst(root);
	size = get_size(root);
	i = 0;
	values = (int*)malloc(size * sizeof(int));
	current = copy;
	while (i < size)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
	sort_values(values, size);
	simplify_values(copy, values, size);
	free(values);
	return (copy);
}

int	get_size(t_list *root)
{
	t_list	*curr;
	int		size;

	curr = root;
	size = 0;
	while (curr != NULL)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}
