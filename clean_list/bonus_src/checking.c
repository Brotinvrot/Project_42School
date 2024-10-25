/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:14:14 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/25 11:36:48 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_header.h"

void	error_func(t_Stack *a, t_Stack *b)
{
	write (1, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	exit (1);
}

void	exec_instruct(char *line, t_Stack *a, t_Stack *b)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_a(a);
	else if (ft_strcmp(line, "sb") == 0)
		swap_b(b);
	else if (ft_strcmp(line, "ss") == 0)
		swap_ss(a, b);
	else if (ft_strcmp(line, "pa") == 0)
		push_a(a, b);
	else if (ft_strcmp(line, "pb") == 0)
		push_b(a, b);
	else if (ft_strcmp(line, "ra") == 0)
		rotate_a(a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_b(b);
	else if (ft_strcmp(line, "rra") == 0)
		rev_ra(a);
	else if (ft_strcmp(line, "rrb") == 0)
		rev_rb(b);
	else if (ft_strcmp(line, "rrr") == 0)
		rev_rr(a, b);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_r(a, b);
	else
		error_func(a, b);
}

void	checking(t_Stack *a, t_Stack *b)
{
	char	line[5];
	char	tmp;
	int		i;

	i = 0;
	while (read(0, &tmp, 1) > 0)
	{
		if (tmp == '\n' || i >= 4)
		{
			line[i] = '\0';
			exec_instruct(line, a, b);
			i = 0;
			ft_memset(line, 0, 5);
		}
		else
		{
			line[i] = tmp;
			i++;
		}
	}
	if (if_it_sort(a) == 0 && b -> top == NULL)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}
