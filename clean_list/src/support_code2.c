/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_code2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:52:27 by macushka          #+#    #+#             */
/*   Updated: 2024/10/01 12:29:37 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_new.h"

int	count_nods(t_Stack *a)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = a -> top;
	while (tmp != NULL)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}

void	sort_two(t_Stack *a)
{
	if (a -> top -> number > a -> end -> number)
		swap_a(a);
}

void	sort_three(t_Stack *a)
{
	if (a -> top -> number > a -> end -> number)
	{
		if (a -> end -> number > a -> top -> next -> number)
			rotate_a(a);
		else
		{
			rotate_a(a);
			swap_a(a);
		}
	}
	else if (a -> top -> number < a -> end -> number)
	{
		if (a -> top -> number > a -> top -> next -> number)
			swap_a(a);
		else
		{
			swap_a(a);
			rotate_a(a);
		}
	}
	else
		rev_ra(a);
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
	if (if_it_sort(a) == 1)
		push_b(a, b);
}

void	sort_four(t_Stack *a, t_Stack *b)
{
	find_min_pb(a, b);
	if (if_it_sort(a) == 0 && b -> top == NULL)
		return ;
	sort_three(a);
	push_a(a, b);
}

void	sort_few()
{
	write(1, "Im in funktion few\n", 19);
}

void	speedrun(t_Stack *a, t_Stack *b)
{
	int	nods;

	nods = count_nods(a);
	if (nods > 5)
		return ;
	if (nods == 2)
		sort_two(a);
	if (nods == 3)
	{
		sort_three(a);
	}
	if (nods == 4)
		sort_four(a, b);
	if (nods == 5)
		sort_few();
	print_stack(a, "a");
	//if_it_sort(a);
	// {
	// 	free_stack(a);
	// 	write (1, "Oshibka BLIAT\n", 14);
	// 	exit (1);
	// }
}
/* в общем идея сортировки такая закинул перых два элемента в стек б потом
 отсортировал их в порядке убывания больший элемент в начало меньший в конец и так по одному закидываешь и
 сортируешь, проверяя куда лучше крутить стек */
