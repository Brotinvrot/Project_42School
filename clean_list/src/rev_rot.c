/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:38:56 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/11 13:38:59 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
