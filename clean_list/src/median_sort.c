/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
<<<<<<<< HEAD:clean_list/src/median_sort.c
/*   Created: 2024/10/11 17:31:16 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/14 08:23:04 by drabadan         ###   ########.fr       */
========
/*   Created: 2024/10/01 13:39:11 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/13 07:45:38 by drabadan         ###   ########.fr       */
>>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3:clean_list/src/support_code1.c
=======
/*   Created: 2024/10/11 17:31:16 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/12 16:10:57 by drabadan         ###   ########.fr       */
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

<<<<<<< HEAD
<<<<<<<< HEAD:clean_list/src/median_sort.c
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

=======
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
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

<<<<<<< HEAD
void	pre_sort(t_Stack *a, t_Stack *b)
=======
void	pre_sort (t_Stack *a, t_Stack *b)
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
{
	recurs_sort_a(a, b);
	if (count_nods(a) == 3)
		sort_three(a);
	if (count_nods(a) == 2)
		sort_two(a);
<<<<<<< HEAD
========
short	if_it_sort(t_Stack *stack)
{
	t_node	*current;
	t_node	*top;

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

void	sort_stack (t_Stack *a, t_Stack *b)
{
	if (if_it_sort (a) == 0)
		return ;
	speedrun (a, b);
	pre_sort (a, b);
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
>>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3:clean_list/src/support_code1.c
=======
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
}
