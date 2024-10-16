/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:30:48 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/13 20:39:23 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_ind(t_Stack *stack)
{
	t_node	*tmp;
	t_node	*min_nod;
	int		i;
	int		num;

	i = 1;
	while (1)
	{
		num = 2147483647;
		min_nod = NULL;
		tmp = stack -> top;
		while (tmp != NULL)
		{
			if (tmp -> number <= num && tmp -> index == -1)
			{
				num = tmp -> number;
				min_nod = tmp;
			}
			tmp = tmp -> next;
		}
		if (min_nod == NULL)
			break ;
		min_nod -> index = i;
		i++;
	}
}

void	init_index(t_Stack *stack)
{
	t_node	*tmp;

	tmp = stack -> top;
	while (tmp != NULL)
	{
		tmp -> index = -1;
		tmp = tmp -> next;
	}
}
