/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:40:49 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/05 21:29:17 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_new.h"

void	push_b(t_Stack *a, t_Stack *b)
{
	t_node	*tmp;

	if (a -> top == NULL)
		return ;
	tmp = a -> top;
	a -> top = a -> top -> next;
	if (a -> top != NULL)
		a -> top -> prev = NULL;
	else
		a -> end = NULL;
	tmp -> next = b -> top;
	tmp -> prev = NULL;
	if (b -> top != NULL)
		b -> top -> prev = tmp;
	else
		b -> end = tmp;
	b -> top = tmp;
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
	a -> top -> prev = a -> top -> next;
	a -> top -> next = a -> top -> next -> next;
	a -> top -> prev -> next = a -> top;
	a -> top = a -> top -> prev;
	a -> top -> next = a -> top -> prev;
	a -> top ->prev = NULL;
	if (a -> top -> next -> next != NULL)
		a -> top -> next -> next -> prev = a -> top -> next;
	write (1, "sa\n", 3);
}

void	swap_b(t_Stack *b)
{
	if (b -> top == NULL || b -> top -> next == NULL)
		return ;
	b -> top -> prev = b -> top -> next;
	b -> top -> next = b -> top -> next -> next;
	b -> top -> prev -> next = b -> top;
	b -> top = b -> top -> prev;
	b -> top = b -> top -> prev;
	b -> top ->prev = NULL;
	if (b -> top -> next -> next != NULL)
		b -> top -> next -> next -> prev = b -> top -> next;
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
	a -> top -> prev -> next = a -> top;
	a -> top = a -> top -> prev;
	a -> top ->prev = NULL;
	b -> top -> prev = b -> top -> next;
	b -> top -> next = b -> top -> next -> next;
	b -> top -> prev -> next = b -> top;
	b -> top = b -> top -> prev;
	b -> top ->prev = NULL;
	write (1, "ss\n", 3);
}
