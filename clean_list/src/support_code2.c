/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_code2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:42:57 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/05 21:29:18 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	test_command(t_Stack *a, t_Stack *b)
{
	for (int i = 0; i < 10; i++)
		push_b (a, b);
	for (int i = 0; i < 10; i++)
	{
		rotate_a(a);
		rotate_b(b);
	}
	for (int i = 0; i < 10; i++)
	{
		rotate_r(a, b);
		print_stack(a, 'a');
	}
}