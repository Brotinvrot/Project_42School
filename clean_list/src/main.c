/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:29:55 by drabadan          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/14 09:35:02 by drabadan         ###   ########.fr       */
=======
/*   Updated: 2024/10/11 17:34:21 by drabadan         ###   ########.fr       */
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	second_step(char **str)
{
	t_Stack	a;
	t_Stack	b;

	init_stack(&a);
	init_stack(&b);
	fill_stack(&a, str);
<<<<<<< HEAD
	init_index(&a);
	fill_ind(&a);
	if (if_it_sort(&a) == 1)
		sort_stack(&a, &b);
=======
	indexing(&a);
	sort_stack(&a, &b);
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
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
<<<<<<< HEAD
	if (argc == 1)
		return (0);
=======
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
	first_step(argc, argv);
	return (0);
}
