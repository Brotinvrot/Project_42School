/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:29:55 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/25 11:12:15 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_header.h"

void	second_step(char **str)
{
	t_Stack	a;
	t_Stack	b;

	init_stack(&a);
	init_stack(&b);
	fill_stack(&a, str);
	if (if_it_sort(&a) == 1)
		checking(&a, &b);
	else
	{
		free_stack(&a);
		free_stack(&b);
		write (1, "OK\n", 3);
		exit(0);
	}
	free_stack(&a);
	free_stack(&b);
}

void	first_step(int argc, char **argv)
{
	int		i;
	char	**str;

	i = 1;
	while (argv[i])
	{
		check_simbl(argv[i]);
		i++;
	}
	str = ft_split(argv, argc, ' ');
	if (str == NULL)
		exit (1);
	i = check_int(str);
	if (i == 1)
	{
		goto_free(str);
		exit (1);
	}
	second_step(str);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	first_step(argc, argv);
	return (0);
}
