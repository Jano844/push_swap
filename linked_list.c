/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:02:47 by jsanger           #+#    #+#             */
/*   Updated: 2023/08/08 15:44:56 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_end(t_list **root, int x)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		exit (1);
	new_node->value = x;
	new_node->next = NULL;

	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	t_list *curr;

	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void deallocate(t_list **root)
{
	t_list *curr = *root;
	while (curr != NULL)
	{
		t_list *temp = curr;
		curr = curr->next;
		free(temp);
	}
	*root = NULL;
}

void add_front(t_list **root, int x)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		exit(1);
	new_node->value = x;
	new_node->next = *root;
	*root = new_node;
}
