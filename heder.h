/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:00:15 by drabadan          #+#    #+#             */
/*   Updated: 2024/06/04 15:51:39 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Our_freedoms
{
	char	*str;
	char	**ar2_d2;
} Our_freedom;

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_stack;

struct s_node	*create_list(int n, char **str, Our_freedom *freedom);
void	print_list(struct s_node *p);
int	ft_atoi(const char *str, Our_freedom *freedom);

#endif
