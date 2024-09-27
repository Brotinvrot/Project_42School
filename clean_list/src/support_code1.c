/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_code1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:52:02 by macushka          #+#    #+#             */
/*   Updated: 2024/09/24 19:17:44 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_new.h"

void	free_stack(t_Stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack -> top;
	while (current != NULL)
	{
		next = current -> next;
		free(current);
		current = next;
	}
	stack -> top = NULL;
	stack -> end = NULL;
}

void	fill_stack(t_Stack *a, char **str)
{
	int			i;
	t_node		*tmp;

	i = 0;
	while (str[i])
	{
		tmp = malloc(sizeof(t_node));
		if (!tmp)
		{
			goto_free(str);
			free_stack(a);
			exit (1);
		}
		tmp -> number = atoi(str[i]);
		tmp -> next = a -> top;
		tmp -> prev = NULL;
		if (a -> top)
			a -> top -> prev = tmp;
		else
			a -> end = tmp;
		a -> top = tmp;
		i++;
	}
	goto_free(str);
}

void	push_min_to_b(t_Stack *a, t_Stack *b)
{
	t_node	*min;
	t_node	*current;

	min = a -> top;
	current = a -> top;
	while (current != NULL)
	{
		if (current -> number < min -> number)
			min = current;
		current = current -> next;
	}
	while (a -> top != min)
		rotate_a(a);
	push_b (a, b);
}

void	sort_stack(t_Stack *a, t_Stack *b)
{
	while (a->top != NULL)
		push_min_to_b(a, b);
	while (b->top != NULL)
		push_a(a, b);
}
