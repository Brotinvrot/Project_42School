/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:40:49 by drabadan          #+#    #+#             */
/*   Updated: 2024/06/09 19:20:15 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heder.h"

void	sa(t_stack_a)
{
	t_stack_a	*tmp;

	t_stack_a tmp = head->next;
	head->next = head->next->next;
	tmp->next = head;
	head = tmp;
}

void	sb(t_stack_b)
{
	t_stack_b	*tmp;

	t_stack_b	
}

void	ss()
{
	
}

void	pa()
{
	
}

void	pb()
{
	
}

void	