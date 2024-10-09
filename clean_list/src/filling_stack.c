/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:59:02 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/07 19:26:49 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void	print_index(t_Stack *stack)
{
	t_node	*tmp;

	tmp = stack -> top;
	while (tmp != NULL)
	{
		printf ("%d ", tmp -> index);
		tmp = tmp -> next;
	}
	printf ("\n");
}

void	indexing(t_Stack *stack)
{
	init_index(stack);
	fill_ind(stack);
	print_index(stack);
}
