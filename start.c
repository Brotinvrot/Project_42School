/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:00:19 by drabadan          #+#    #+#             */
/*   Updated: 2024/07/07 19:34:37 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heder.h"

size_t	ft_strlen(const char *str)//перенёс
{
	size_t	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)//перенёс
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *src)//перенёс
{
	char	*point;
	int		len_src;

	if (src == NULL)
		return (NULL);
	len_src = ft_strlen(src);
	point = (char *)malloc(len_src + 1);
	if (point == NULL)
		return (NULL);
	while (*src)
		*point++ = *src++;
	*point = '\0';
	return (point - len_src);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)//перенёс
{
	char	*new_str;
	size_t	com_size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	com_size = ft_strlen(s + start);
	if (com_size < len)
		len = com_size;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s + start, len + 1);
	return (new_str);
}

static int	word_counter(char const *s, char c)//пeренес
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

void	put(char const *s, char c, char **result)//перенес
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

char	**ft_split(char const *s, char c)//перенес
{
	int		word_count;
	char	**result;

	word_count = word_counter(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	put(s, c, result);
	return (result);
}

int	total_length(int argc, char **argv)//перенёс
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

char	*str_creat(char *str, int argc, char **argv)//перенёс
{
	int	i;

	i = 2;
	strcpy(str, argv[1]);
	while (i < argc)
	{
		strcat(str, " ");
		strcat(str, argv[i]);
		i++;
	}
	return (str);
}

int	chek_simbl(char *str)//перенёс код
{
	while (*str)
	{
		if ((*str >= 48 && *str <= 57) || *str == 32)
		{
			if ((*str >= 48 && *str <= 57) && *(str + 1) == 45)
				return (printf("invalid characters\n"), 1);
			else
				str++;
		}
		else
		{
			if (*str == 45 && *(str + 1) >= 48 && *(str + 1) <= 57)
				str ++;
			else
				return (printf("invalid characters\n"), 1);
		}
	}
	return (0);
}

void	ft_free(Our_freedom *freedom)
{
	int	i;

	i = 0;
	free(freedom->str);
	while (freedom->ar2_d2[i])
	{
		free(freedom->ar2_d2[i]);
		i++;
	}
	free(freedom->ar2_d2);
}

void	error_and_exit(Our_freedom *freedom)
{
	ft_free(freedom);
	exit (printf("invalid characters\n"));
}

int	ft_atoi(const char *str, Our_freedom *freedom)//перенёс
{
	long	n;
	short	sim;
	int		i;

	n = 0;
	sim = 1;
	i = 0;
	if (*str == '-')
	{
		sim = -1;
		str++;
		if (*str == '0')
			error_and_exit(freedom);
	}
	if (*str == '0' && (*(str + 1) >= '0' && *(str + 1) <= '9'))
		error_and_exit(freedom);
	while (*str)
	{
		n = n * 10 + (*str - '0');
		str++;
		i++;
		if (i > 12)
			error_and_exit(freedom);
	}
	n *= sim;
	if (n >= -2147483648 && n <= 2147483647)
		return(n);
	else
		error_and_exit(freedom);
	return (-1);
}

void	chek_doubl(char **str, Our_freedom *freedom)//перенёс
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
			if ((strcmp (str[i], str[j]) == 0))
			{
				ft_free(freedom);
				exit (printf("Duplicate found\n"));
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	Our_freedom		freedom;
	struct s_node	*temp;
	struct s_node	*head;
	int			total_len;
	int					i;

	if (argc < 2) 
		return (1);//скопировал
	total_len = total_length(argc, argv);
	freedom.str = (char *)malloc(total_len + argc);
	if (freedom.str == NULL) 
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	str_creat(freedom.str, argc, argv);
	if (chek_simbl(freedom.str) == 1)
	{
		free(freedom.str);
		return (1);
	}
	freedom.ar2_d2 = ft_split(freedom.str, ' ');
	chek_doubl(freedom.ar2_d2, &freedom);
	i = 0;
	while (freedom.ar2_d2[i])
		i++;
	head = create_list(i, freedom.ar2_d2, &freedom);
	if(head != NULL)
	{
		print_list(head);
		while (head != NULL)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
	}
	ft_free(&freedom);
	return (0);
}
