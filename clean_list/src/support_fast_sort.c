/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_fast_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:38:37 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/14 08:41:30 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_to_min(t_Stack *a, int min, int index_min, int max_index)
{
	if (index_min > (max_index - index_min - 1))
	{
		while (a -> top -> number != min)
		{
			rev_ra (a);
			if (if_it_sort (a) == 0)
				return ;
		}
	}
	else
	{
		while (a -> top -> number != min)
		{
			rotate_a(a);
			if (if_it_sort (a) == 0)
				return ;
		}
	}
}

void	find_min_pb(t_Stack *a, t_Stack *b)
{
	t_node	*tmp;
	int		min;
	int		max_index;
	int		index_min;

	tmp = a -> top;
	min = tmp -> number;
	max_index = 0;
	index_min = 0;
	while (tmp != NULL)
	{
		if (tmp -> number < min)
		{
			min = tmp -> number;
			index_min = max_index;
		}
		tmp = tmp -> next;
		max_index++;
	}
	rotate_to_min (a, min, index_min, max_index);
	push_b (a, b);
}
