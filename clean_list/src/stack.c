/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:28:32 by drabadan          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/13 20:19:12 by drabadan         ###   ########.fr       */
=======
/*   Updated: 2024/10/11 13:36:27 by drabadan         ###   ########.fr       */
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_stack(t_Stack *stack)
{
	stack -> top = NULL;
	stack -> end = NULL;
}

void	fill_stack(t_Stack *a, char **str)
{
	int			i;
	t_node		*tmp;

	i = 0;
	while (str[i])
	{
		tmp = malloc(sizeof(t_node));
		if (!tmp)
		{
			goto_free(str);
			free_stack(a);
			exit (1);
		}
<<<<<<< HEAD
		tmp -> number = ft_atoi(str[i]);
=======
		tmp -> number = atoi(str[i]);
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
		tmp -> next = NULL;
		tmp -> prev = a -> end;
		if (a -> end)
			a -> end -> next = tmp;
		a -> end = tmp;
		if (a -> top == NULL)
			a -> top = tmp;
		i++;
	}
	goto_free(str);
}
