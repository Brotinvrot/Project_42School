/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_code1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:11 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/12 21:54:47 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	printf("Ja zahogu!\n");
	pre_sort (a, b);
	sleep(1);
	print_index (a);
	print_index (b);
	printf("index = %d", best_case (a, b));
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
