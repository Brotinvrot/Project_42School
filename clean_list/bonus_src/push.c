/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:33:22 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/16 11:29:40 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_header.h"

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
}
