/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:31:16 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/12 16:10:57 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	find_median(t_Stack *stack)
{
	t_node	*tmp;
	int		max_index;
	int		min_index;
	int		median;

	tmp = stack -> top;
	max_index = tmp -> index;
	min_index = tmp -> index;
	while (tmp != NULL)
	{
		if (tmp -> index < min_index)
			min_index = tmp -> index;
		else if (tmp -> index > max_index)
			max_index = tmp -> index;
		tmp = tmp -> next;
	}
	median = ((max_index - min_index) / 2) + min_index;
	return (median);
}

void	recurs_sort_a(t_Stack *a, t_Stack *b)
{
	int	median;
	int	first_left_index;

	first_left_index = -1;
	if (count_nods(a) <= 3)
		return ;
	median = find_median(a);
	while (a -> top != NULL && a -> top -> index != first_left_index)
	{
		if (a -> top -> index < median)
			push_b (a, b);
		else
		{
			if (first_left_index == -1)
				first_left_index = a -> top -> index;
			rotate_a (a);
		}
	}
	recurs_sort_a(a, b);
}

void	pre_sort (t_Stack *a, t_Stack *b)
{
	recurs_sort_a(a, b);
	if (count_nods(a) == 3)
		sort_three(a);
	if (count_nods(a) == 2)
		sort_two(a);
}
