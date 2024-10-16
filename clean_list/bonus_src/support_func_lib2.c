/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_func_lib2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:39:11 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/16 10:55:37 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_header.h"

void	*ft_memset(void *dst, int n, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)dst;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)n;
		i++;
	}
	return (dst);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
