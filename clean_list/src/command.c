/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:40:49 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/06 18:40:27 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_b(t_Stack *a, t_Stack *b)
{
	t_node	*tmp;

	if (a -> top == NULL)
		return ;
	tmp = a -> top;
	if (tmp -> next == NULL)
	{
		a -> top = NULL;
		a -> end = NULL;
	}
	else
	{
		a -> top = a -> top -> next;
		a -> top -> prev = NULL;
	}
	if (b -> top == NULL)
	{
		b -> top = tmp;
		b -> end = tmp;
		b -> top -> prev = NULL;
		b -> end -> next = NULL;
	}
	else
	{
		tmp -> next = b -> top;
		b -> top -> prev = tmp;
		b -> top = tmp;
	}
	write (1, "pb\n", 3);
}

void	push_a(t_Stack *a, t_Stack *b)
{
	t_node	*tmp;

	if (b -> top == NULL)
		return ;
	tmp = b -> top;
	b -> top = b -> top -> next;
	if (b -> top != NULL)
		b -> top -> prev = NULL;
	else
		b -> end = NULL;
	tmp -> next = a -> top;
	tmp -> prev = NULL;
	if (a -> top != NULL)
		a -> top -> prev = tmp;
	else
		a -> end = tmp;
	a -> top = tmp;
	write (1, "pa\n", 3);
}

void	swap_a(t_Stack *a)
{
	if (a -> top == NULL || a -> top -> next == NULL)
		return ;
	if (a -> top -> next -> next == NULL)
	{
		a -> top = a -> end;
		a -> end = a -> top -> prev;
		a -> top -> next = a -> end;
		a -> end -> prev = a -> top;
		a -> top -> prev = NULL;
		a -> end -> next = NULL;
	}
	else
	{
		a -> top -> prev = a -> top -> next;
		a -> top -> next = a -> top -> next -> next;
		a -> top -> prev -> next = a -> top;
		a -> top -> next -> prev = a -> top;
		a -> top = a -> top -> prev;
		a -> top -> prev = NULL;
	}
	write (1, "sa\n", 3);
}

void	swap_b(t_Stack *b)
{
	if (b -> top == NULL || b -> top -> next == NULL)
		return ;
	if (b -> top -> next -> next == NULL)
	{
		b -> top = b -> end;
		b -> end = b -> top -> prev;
		b -> top -> next = b -> end;
		b -> end -> prev = b -> top;
		b -> top -> prev = NULL;
		b -> end -> next = NULL;
	}
	else
	{
		b -> top -> prev = b -> top -> next;
		b -> top -> next = b -> top -> next -> next;
		b -> top -> prev -> next = b -> top;
		b -> top -> next -> prev = b -> top;
		b -> top = b -> top -> prev;
		b -> top -> prev = NULL;
	}
	write (1, "sb\n", 3);
}

void	swap_ss(t_Stack *a, t_Stack *b)
{
	if (a -> top == NULL || a -> top -> next == NULL)
		return ;
	if (b -> top == NULL || b -> top -> next == NULL)
		return ;
	a -> top -> prev = a -> top -> next;
	a -> top -> next = a -> top -> next -> next;
	if (a -> top -> next != NULL)
		a -> top -> next -> prev = a -> top;
	a -> top -> prev -> next = a -> top;
	a -> top = a -> top -> prev;
	a -> top -> prev = NULL;
	b -> top -> prev = b -> top -> next;
	b -> top -> next = b -> top -> next -> next;
	if (b -> top -> next != NULL)
		b -> top -> next -> prev = b -> top;
	b -> top -> prev -> next = b -> top;
	b -> top = b -> top -> prev;
	b -> top ->prev = NULL;
	write (1, "ss\n", 3);
}
