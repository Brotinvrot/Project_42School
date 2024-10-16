/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 00:01:47 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/14 20:07:01 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	r_or_rr_stack_a(t_Stack *stack, int index)
{
	t_node	*tmp;
	int		from_the_top;
	int		from_the_end;

	from_the_top = 0;
	from_the_end = 0;
	tmp = stack -> top;
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
	if (from_the_top < from_the_end)
		while (stack -> top -> index != index)
			rotate_a(stack);
	else
		while (stack -> top -> index != index)
			rev_ra(stack);
}

void	r_or_rr_stack_b(t_Stack *stack, int index)
{
	t_node	*tmp;
	int		from_the_top;
	int		from_the_end;

	from_the_top = 0;
	from_the_end = 0;
	tmp = stack -> top;
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
	if (from_the_top < from_the_end)
		while (stack -> top -> index != index)
			rotate_b(stack);
	else
		while (stack -> top -> index != index)
			rev_rb(stack);
}

void	find_best_place_new(t_Stack *a, t_Stack *b, int max_index)
{
	int		current_index;
	t_node	*tmp;

	current_index = best_case(a, b);
	tmp = a -> top;
	while (tmp != NULL)
	{
		if (tmp -> index > current_index && tmp -> index < max_index)
			max_index = tmp -> index;
		tmp = tmp -> next;
	}
	r_or_rr_stack_b(b, current_index);
	r_or_rr_stack_a(a, max_index);
	push_a (a, b);
}

void	greedy_sort(t_Stack *a, t_Stack *b)
{
	while (b -> top != NULL)
		find_best_place_new(a, b, find_max_or_min_index(a, 1));
	r_or_rr_stack_a(a, find_max_or_min_index(a, -1));
}

void	sort_stack(t_Stack *a, t_Stack *b)
{
	speedrun (a, b);
	pre_sort (a, b);
	greedy_sort (a, b);
	if (if_it_sort(a) == 0)
	{
		free_stack (a);
		free_stack (b);
		exit (0);
	}
}
