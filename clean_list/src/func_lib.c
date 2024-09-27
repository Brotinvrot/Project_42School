/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:22:55 by macushka          #+#    #+#             */
/*   Updated: 2024/09/24 15:35:45 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_new.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
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

char	*ft_strdup(const char *src)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

char	**ft_split(char **argv, int argc, char c)
{
	int		word_count;
	int		len;
	char	**result;
	char	*s;

	len = total_length(argc, argv);
	s = (char *)malloc(len + argc);
	if (s == NULL)
		return (NULL);
	str_creat(s, argc, argv);
	word_count = word_counter(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
	{
		free(s);
		return (NULL);
	}
	put(s, c, result);
	free(s);
	if (chek_doubl(result) == 0)
		return (result);
	goto_free(result);
	return (NULL);
}
