/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_code2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:42:57 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/06 18:50:51 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	test_command(t_Stack *a, t_Stack *b)
{
	for (int i = 0; i < 2; i++)
	{
		push_b (a, b);
		print_stack(a, 'a');
		print_stack(b, 'b');
	}
	swap_ss(a, b);
	sleep(1);
	print_stack(a, 'a');
	sleep(1);
	print_stack(b, 'b');
	for (int i = 0; i < 10; i++)
	{
		rotate_a(a);
		print_stack(a, 'a');
		print_stack(b, 'b');
		rotate_b(b);
		sleep(1);
		print_stack(a, 'a');
		sleep(1);
		print_stack(b, 'b');
	}
	// for (int i = 0; i < 10; i++)
	// {
	// 	rev_rr(a, b);
	// 	print_stack(a, 'a');
	// 	print_stack(b, 'b');
	// }
	// for (int i = 0; i < 10; i++)
	// {
	// 	rotate_r(a, b);
	// 	print_stack(a, 'a');
	// 	print_stack(b, 'b');
	// }
	for (int i = 0; i < 10; i++)
	{
		swap_a(a);
		swap_b(b);
		swap_ss (a, b);
		print_stack(a, 'a');
		print_stack(b, 'b');
	}
}
