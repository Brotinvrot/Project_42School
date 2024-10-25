/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:04:09 by drabadan          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/14 20:17:39 by drabadan         ###   ########.fr       */
=======
/*   Updated: 2024/10/12 15:16:03 by drabadan         ###   ########.fr       */
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

<<<<<<< HEAD
void	sort_two(t_Stack *stack)
=======
void	sort_two(t_Stack *stack)// можно удалить тут и переписать в спидране если больше нигде не используется и не вызывается
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
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
<<<<<<< HEAD
=======

>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
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
	sort_three(a);
	push_a(a, b);
}

void	sort_few(t_Stack *a, t_Stack *b)
{
	find_min_pb(a, b);
	find_min_pb(a, b);
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
	if (if_it_sort(a) == 0)
	{
<<<<<<< HEAD
=======
		write (1, "Sort\n", 5);
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
		free_stack(a);
		free_stack(b);
		exit (0);
	}
<<<<<<< HEAD
=======
	else
		write (1, "Ne sort\n", 8);
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
}
