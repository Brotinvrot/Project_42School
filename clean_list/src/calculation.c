/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:24:10 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/12 21:58:08 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	move_to_the_top(t_Stack *stack, int index)// высчитываем сколько ходов требуется для перемещения в топ того или иного индекса
{
	t_node	*tmp;
	int		from_the_top;
	int		from_the_end;

	from_the_top = 0;
	from_the_end = 0;
	tmp	= stack -> top;
	if (tmp -> index == index)
		return (from_the_top);
	while (tmp != NULL && tmp -> index != index)
	{
		from_the_top++;
		tmp = tmp -> next;
	}
	tmp = stack -> end;
	while (tmp != NULL && tmp -> index != index)
	{
		from_the_end++;
		tmp = tmp -> prev;
	}
	if (from_the_end < from_the_top)
		return (from_the_end);
	else
		return (from_the_top);
}

int	find_place(t_Stack *a, int index_b)// Находим индекс подходящей ноды что бы запушить ему на голову.
{
	t_node	*tmp;
	int		max_index_a;

	tmp = a -> top;
	max_index_a = find_max_or_min_index(a, 1);
	while (tmp != NULL)
	{
		if (tmp -> index > index_b && tmp -> index < max_index_a)
			max_index_a = tmp -> index;
		tmp = tmp -> next;
	}
	return (max_index_a);
}

int	best_case(t_Stack *a, t_Stack *b)
{
	t_node	*tmp_b;
	int		sum;
	int		final_sum;
	int		index;

	final_sum = -1;
	tmp_b = b -> top;
	index = tmp_b -> index;
	while (tmp_b != NULL)
	{
		sum = 0;
		sum += move_to_the_top(b, tmp_b -> index);
		sum += move_to_the_top(a, find_place(a, tmp_b -> index));
		if (final_sum != -1 && final_sum > sum)
		{
			final_sum = sum;
			index = tmp_b -> index;
		}
		else if (final_sum == -1)
			final_sum = sum;
		tmp_b = tmp_b -> next;
	}
	return (index);
}
