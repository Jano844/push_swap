/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:02:47 by jsanger           #+#    #+#             */
/*   Updated: 2023/08/07 20:09:16 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	ft_lstnew(int val)
{
	t_list	*root;

	root = NULL;
	root = malloc(sizeof(t_list));
	if (root == NULL)
		exit (0);
	root->value = val;
	root->next = NULL;
	return (root);
}

void addback(t_list **root, int val)
