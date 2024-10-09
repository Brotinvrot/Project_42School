/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_code1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:11 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/08 14:17:49 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_stack(t_Stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack -> top;
	while (current != NULL)
	{
		next = current -> next;
		free(current);
		current = next;
	}
	stack -> top = NULL;
	stack -> end = NULL;
}

void	push_min_to_b(t_Stack *a, t_Stack *b)
{
	t_node	*min;
	t_node	*current;

	min = a -> top;
	current = a -> top;
	while (current != NULL)
	{
		if (current -> number < min -> number)
			min = current;
		current = current -> next;
	}
	while (a -> top != min)
		rotate_a(a);
	push_b (a, b);
}

short	if_it_sort(t_Stack *stack)
{
	t_node	*current;
	t_node		*top;

	if (!stack || !stack -> top)
		return (0);
    top = stack -> top;
    current = stack -> top -> next;
	while (current != NULL)
	{
		if (top->number < current->number)
		{
			top = current;
			current = top->next;
		}
		else
			return (1);
	}
	return (0);
}

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

void	recurs_sort(t_Stack *a, t_Stack *b)
{
	int	median;
	int	first_left_index;

	first_left_index = -1;
	if (count_nods(a) <= 3)
		return ;
	median = find_median(a);
	printf("median = %d\n", median);
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
	recurs_sort(a, b);
}

void	pre_sort(t_Stack *a, t_Stack *b)
{
	recurs_sort(a, b);
	if (count_nods(a) == 3)
		sort_three(a);
	if (count_nods(a) == 2)
		sort_two(a);
}

void	sort_stack (t_Stack *a, t_Stack *b)
{
	if (if_it_sort (a) == 0)
		return ;
	speedrun (a, b);
	pre_sort (a, b);
	print_stack (a, 'a');
	print_stack (b, 'b');
	// while (a->top != NULL)
	// 	find_min_pb(a, b);
	// while (b->top != NULL)
	// 	push_a(a, b);
	sort_stack_1(a, b);
	if (if_it_sort(a) == 0)
	{
		write (1, "Sort\n", 5);
		free_stack(a);
		free_stack(b);
		exit (0);
	}
	else
		write (1, "Ne sort\n", 8);
}
