/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_code1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:11 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/05 20:31:19 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
		tmp -> next = NULL;
		tmp -> prev = a -> end;
		if (a -> end)
			a -> end -> next = tmp;
		a -> end = tmp;
		if (a -> top == NULL)
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

short	if_it_sort(t_Stack *stack)
{
	t_node	*current;
	t_node		*top;

	if (!stack || !stack -> top)
		return (0);
    top = stack -> top;
    current = stack -> top -> next;
	while (current != NULL)
	{
		if (top->number < current->number)
		{
			top = current;
			current = top->next;
		}
		else
			return (1);
	}
	return (0);
}

void	sort_stack(t_Stack *a, t_Stack *b)
{
	swap_a (a);
	if (if_it_sort (a) == 0)
		return ;
	while (a->top != NULL)
		push_min_to_b(a, b);
	while (b->top != NULL)
		push_a(a, b);
}
