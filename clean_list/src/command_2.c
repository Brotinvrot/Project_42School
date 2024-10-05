/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:03:08 by macushka          #+#    #+#             */
/*   Updated: 2024/10/04 09:16:45 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_new.h"

void	rev_rr(t_Stack *a, t_Stack *b)
{
	if (a -> top == NULL || a -> top -> next == NULL)
		return ;
	if (b -> top == NULL || b -> top -> next == NULL)
		return ;
	a -> end -> next = a -> top;
	a -> top -> prev = a -> end;
	a -> end = a -> end -> prev;
	a -> end -> next = NULL;
	a -> top = a -> top -> prev;
	a -> top -> prev = NULL;
	b -> end -> next = b -> top;
	b -> top -> prev = b -> end;
	b -> end = b -> end -> prev;
	b -> end -> next = NULL;
	b -> top = b -> top -> prev;
	b -> top -> prev = NULL;
	write(1, "rrr\n", 4);
}

void	init_stack(t_Stack *stack)
{
	stack -> top = NULL;
	stack -> end = NULL;
}

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

void	print_stack(t_Stack *stack, char c)
{
	t_node	*tmp;

	tmp = stack -> top;
	printf ("%c\n", c);
	while (tmp != NULL)
	{
		printf ("%d ", tmp -> number);
		tmp = tmp -> next;
	}
	printf ("\n");
}

void	print_stack_index(t_Stack *stack)
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
