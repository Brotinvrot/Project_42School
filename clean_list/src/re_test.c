/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:17:42 by macushka          #+#    #+#             */
/*   Updated: 2024/10/04 22:28:14 by macushka         ###   ########.fr       */
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

void	init_index(t_Stack *a)
{
	t_node	*tmp;

	tmp = a -> top;
	while (tmp != NULL)
	{
		tmp -> index = -1;
		tmp = tmp -> next;
	}
}

void	fill_ind(t_Stack *a)
{
	t_node	*tmp;
	t_node	*min_nod;
	int		i;
	int		num;

	i = 0;
	while (1)
	{
		num = 2147483647;
		min_nod = NULL;
		tmp = a -> top;
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

void	second_step(char **str)
{
	t_Stack	a;
	t_Stack	b;

	init_stack(&a);
	init_stack(&b);
	fill_stack(&a, str);
	init_index(&a);
	fill_ind(&a);
	sort_stack(&a, &b);
	if (if_it_sort(&a) == 1)
		write (1, "Ne sort\n", 8);
	else
		write (1, "Sort\n", 5);
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
	first_step(argc, argv);
	return (0);
}
