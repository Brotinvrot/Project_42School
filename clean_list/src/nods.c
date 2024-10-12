/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:30:48 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/11 13:36:16 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		write (2,"Error\n", 1);
		return (new_node);
	}
	new_node -> number = value;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return (new_node);
}

void	fill_ind(t_Stack *stack)
{
	t_node	*tmp;
	t_node	*min_nod;
	int		i;
	int		num;

	i = 1;
	while (1)
	{
		num = 2147483647;
		min_nod = NULL;
		tmp = stack -> top;
		while (tmp != NULL)
		{
			if (tmp -> number <= num && tmp -> index == -1)
			{
				num = tmp -> number;
				min_nod = tmp;
			}
			tmp = tmp -> next;
		}
		if (min_nod == NULL)
			break ;
		min_nod -> index = i;
		i++;
	}
}

void	init_index(t_Stack *stack)
{
	t_node	*tmp;

	tmp = stack -> top;
	while (tmp != NULL)
	{
		tmp -> index = -1;
		tmp = tmp -> next;
	}
}

void	indexing(t_Stack *stack)
{
	init_index(stack);
	fill_ind(stack);
}
