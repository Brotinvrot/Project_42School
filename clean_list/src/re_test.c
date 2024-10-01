/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:17:42 by macushka          #+#    #+#             */
/*   Updated: 2024/10/01 11:15:55 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_new.h"

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
	sort_stack(&a, &b);
	// free_stack(&a);
	// free_stack(&b); 
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
