/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_code2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:42:57 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/11 17:25:16 by drabadan         ###   ########.fr       */
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

void	sort_two(t_Stack *stack)
{
	if (stack -> top -> number > stack -> end -> number)
		swap_a(stack);
}

void	sort_three(t_Stack *a)
{
	int	top;
	int	midl;
	int	end;

	top = a -> top -> number;
	midl = a -> top -> next -> number;
	end = a -> end -> number;

	if (top > midl && midl > end)
	{
		swap_a (a);
		rev_ra (a);
	}
	else if (top > end && end > midl)
		rotate_a (a);
	else if (midl < top && top < end)
		swap_a (a);
	else if (midl > top && top > end)
		rev_ra (a);
	else if (top < end && end < midl)
	{
		swap_a (a);
		rotate_a (a);
	}
}

void	sort_four(t_Stack *a, t_Stack *b)
{
	find_min_pb(a, b);
	if (if_it_sort(a) == 0 && b -> top == NULL)
		return ;
	sort_three(a);
	push_a(a, b);
}

void	sort_few(t_Stack *a, t_Stack *b)
{
	find_min_pb(a, b);
	if (if_it_sort(a) == 0 && b -> top == NULL)
		return ;
	find_min_pb(a, b);
	if (if_it_sort(a) == 0 && b -> top == NULL)
		return ;
	sort_three(a);
	push_a(a, b);
	push_a(a, b);
}

int	count_nods(t_Stack *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack -> top;
	while (tmp != NULL)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}

void	speedrun(t_Stack *a, t_Stack *b)
{
	int	nods;

	nods = count_nods(a);
	if (nods > 5)
		return ;
	if (nods == 2)
		sort_two(a);
	else if (nods == 3)
		sort_three(a);
	else if (nods == 4)
		sort_four(a, b);
	else if (nods == 5)
		sort_few(a, b);
	print_stack (a, 'a');
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
