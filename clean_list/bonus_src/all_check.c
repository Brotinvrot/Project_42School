/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:34:37 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/16 10:52:51 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_header.h"

void	check_simbl(char *str)
{
	while (*str)
	{
		if ((*str >= 48 && *str <= 57) || *str == 32)
		{
			if ((*str >= 48 && *str <= 57) && *(str + 1) == 45)
			{
				write (2, "Error\n", 6);
				exit (1);
			}
			else
				str++;
		}
		else
		{
			if (*str == 45 && *(str + 1) > 48 && *(str + 1) <= 57)
				str ++;
			else
			{
				write (2, "Error\n", 6);
				exit (1);
			}
		}
	}
}

int	chek_doubl(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if ((ft_strcmp (str[i], str[j]) == 0))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_int(char **str)
{
	int		i;
	long	num;

	i = 0;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num < -2147483648 || num > 2147483647)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

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
