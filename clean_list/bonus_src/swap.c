/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:40:10 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/16 11:24:01 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_header.h"

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
}

void	swap(t_Stack *stack)
{
	if (stack -> top -> next -> next == NULL)
	{
		stack -> top = stack -> end;
		stack -> end = stack -> top -> prev;
		stack -> top -> next = stack -> end;
		stack -> end -> prev = stack -> top;
		stack -> top -> prev = NULL;
		stack -> end -> next = NULL;
	}
	else
	{
		stack -> top -> prev = stack -> top -> next;
		stack -> top -> next = stack -> top -> next -> next;
		stack -> top -> prev -> next = stack -> top;
		stack -> top -> next -> prev = stack -> top;
		stack -> top = stack -> top -> prev;
		stack -> top -> prev = NULL;
	}
}

void	swap_ss(t_Stack *a, t_Stack *b)
{
	if (a -> top == NULL || a -> top -> next == NULL)
		return ;
	if (b -> top == NULL || b -> top -> next == NULL)
		return ;
	swap(a);
	swap(b);
}
