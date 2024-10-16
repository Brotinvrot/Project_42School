/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:14:14 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/16 12:08:14 by drabadan         ###   ########.fr       */
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
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap_a(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap_b(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		swap_ss(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push_a(a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_b(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate_a(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate_b(b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rev_ra(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rev_rb(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rev_rr(a, b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rotate_r(a, b);
	else
		error_func(a, b);
}

void	checking(t_Stack *a, t_Stack *b)
{
	char	line[5];

	while (read(0, line, 4) > 0)
	{
		exec_instruct(line, a, b);
		ft_memset(line, 0, 5);
	}
	if (if_it_sort(a) == 0 && b -> top == NULL)
	{
		write (1, "OK\n", 3);
		free_stack(a);
		free_stack(b);
	}
	else
	{
		write (1, "KO\n", 3);
		free_stack(a);
		free_stack(b);
	}
}
