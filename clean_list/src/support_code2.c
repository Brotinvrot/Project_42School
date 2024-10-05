/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_code2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:52:27 by macushka          #+#    #+#             */
/*   Updated: 2024/10/04 18:34:01 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_new.h"

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

void	sort_two(t_Stack *a)
{
	if (a -> top -> number > a -> end -> number)
		swap_a(a);
}

void	sort_three(t_Stack *a)
{
	int	top;
	int	midl;
	int	end;

	top = a -> top -> number;
	midl = a -> top -> next -> number;
	end = a -> end -> number;

	if (top > midl && midl > end)//C B A
	{
		swap_a (a);
		rev_ra (a);
	}
	else if (top > end && end > midl)// C A B
		rotate_a (a);
	else if (midl < top && top < end)// B A C
		swap_a (a);
	else if (midl > top && top > end)// B C A
		rev_ra (a);
	else if (top < end && end < midl)// A C B
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
/* в общем идея сортировки такая закинул перых два элемента в стек б потом
 отсортировал их в порядке убывания больший элемент в начало меньший в конец и так по одному закидываешь и
 сортируешь, проверяя куда лучше крутить стек */
