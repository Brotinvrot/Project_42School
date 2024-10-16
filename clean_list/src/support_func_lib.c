/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_func_lib.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:46:48 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/13 19:46:52 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	word_counter(char const *s, char c)
{
	int	w;

	w = 0;
	while (*s)
	{
		if (*s != c)
		{
			w++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (w);
}

void	put(char const *s, char c, char **result)
{
	int			j;
	const char	*start;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[j] = ft_substr(start, 0, s - start);
			if (!result[j++])
			{
				while (--j >= 0)
					free(result[j]);
				free(result);
				return ;
			}
		}
		else
			s++;
	}
	result[j] = NULL;
}

char	*str_creat(char *str, int argc, char **argv)
{
	int	i;

	i = 2;
	ft_strcpy(str, argv[1]);
	while (i < argc)
	{
		ft_strcat(str, " ");
		ft_strcat(str, argv[i]);
		i++;
	}
	return (str);
}

int	total_length(int argc, char **argv)
{
	int	n;
	int	i;

	n = 0;
	i = 1;
	while (i < argc)
	{
		n += ft_strlen(argv[i]);
		i++;
	}
	return (n);
}

long	ft_atoi(const char *str)
{
	long	n;
	short	sim;

	n = 0;
	sim = 1;
	if (*str == '-')
	{
		sim = -1;
		str++;
	}
	if (*str == '0' && (*(str + 1) >= '0' && *(str + 1) <= '9'))
		return (2147483648);
	while (*str)
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * sim);
}
