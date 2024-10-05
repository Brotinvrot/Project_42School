/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_code1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:52:02 by macushka          #+#    #+#             */
/*   Updated: 2024/10/05 16:15:06 by drabadan         ###   ########.fr       */
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

short	if_it_sort(t_Stack *a)
{
	t_node	*current;
	t_node		*top;

	if (!a || !a -> top)
		return (0);
    top = a -> top;
    current = a -> top -> next;
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
	if (if_it_sort(a) == 0)
	{
		free_stack(a);
		exit (0);
	}
	speedrun(a, b);
	general_sort (a, b);
}
