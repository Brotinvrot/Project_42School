/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:29:55 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/07 16:07:04 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void	second_step(char **str)
{
	t_Stack	a;
	t_Stack	b;

	init_stack(&a);
	init_stack(&b);
	fill_stack(&a, str);
	indexing(&a);
	//test_command(&a, &b);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
}

void	first_step(int argc, char **argv)
{
	int		i;
	char	**str;

	if (argc < 2)
		exit (1);
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
	if (argc == 2)
		return (0);
	first_step(argc, argv);
	return (0);
}
