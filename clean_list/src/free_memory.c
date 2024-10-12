/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:21:31 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/11 17:27:34 by drabadan         ###   ########.fr       */
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

void	goto_free(char **str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
		str = NULL;
	}
}
