/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:40:49 by drabadan          #+#    #+#             */
/*   Updated: 2024/07/04 20:02:04 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_new.h"

void    push_B(t_Stack *stack_A, t_Stack *stack_B)
{
    t_node  *tmp;

    if (stack_A -> top == NULL)
        return ;
    tmp = stack_A -> top;
    stack_A -> top = stack_A -> top -> next;
    if (stack_A -> top != NULL)
        stack_A -> top -> prev = NULL;
    else
        stack_A -> end = NULL;
    tmp -> next = stack_B -> top;
    tmp -> prev = NULL;
    if (stack_B -> top != NULL)
        stack_B -> top -> prev = tmp;
    else
        stack_B -> end = tmp;
    stack_B -> top = tmp;
    write (1, "pb\n", 3);
}

void    push_A(t_Stack *stack_A, t_Stack *stack_B)
{
    t_node  *tmp;

    if (stack_B -> top == NULL)
        return ;
    tmp = stack_B -> top;
    stack_B -> top = stack_B -> top -> next;
    if (stack_B -> top != NULL)
        stack_B -> top -> prev = NULL;
    else
        stack_B -> end = NULL;
    tmp -> next = stack_A -> top;
    tmp -> prev = NULL;
    if (stack_A -> top != NULL)
        stack_A -> top -> prev = tmp;
    else
        stack_A -> end = tmp;
    stack_A -> top = tmp;
    write (1, "pa\n", 3);
}

void    swap_A(t_Stack *stack_A)
{
    if (stack_A -> top == NULL || stack_A -> top -> next == NULL)
        return ;
    stack_A -> top -> prev = stack_A -> top -> next;
    stack_A -> top -> next = stack_A -> top -> next -> next;
    stack_A -> top -> prev -> next = stack_A -> top;
    stack_A -> top = stack_A -> top -> prev;
    stack_A -> top ->prev = NULL;
    write (1, "sa\n", 3);
}

void    swap_B(t_Stack *stack_B)
{
    if (stack_B -> top == NULL || stack_B -> top -> next == NULL)
        return ;
    stack_B -> top -> prev = stack_B -> top -> next;
    stack_B -> top -> next = stack_B -> top -> next -> next;
    stack_B -> top -> prev -> next = stack_B -> top;
    stack_B -> top = stack_B -> top -> prev;
    stack_B -> top ->prev = NULL;
    write (1, "sb\n", 3);
}

void    swap_SS(t_Stack *stack_A, t_Stack *stack_B)
{
    if (stack_A -> top == NULL || stack_A -> top -> next == NULL)
        return ;
    if (stack_B -> top == NULL || stack_B -> top -> next == NULL)
        return ;
    stack_A -> top -> prev = stack_A -> top -> next;
    stack_A -> top -> next = stack_A -> top -> next -> next;
    stack_A -> top -> prev -> next = stack_A -> top;
    stack_A -> top = stack_A -> top -> prev;
    stack_A -> top ->prev = NULL;
    stack_B -> top -> prev = stack_B -> top -> next;
    stack_B -> top -> next = stack_B -> top -> next -> next;
    stack_B -> top -> prev -> next = stack_B -> top;
    stack_B -> top = stack_B -> top -> prev;
    stack_B -> top ->prev = NULL;
    write (1, "ss\n", 3);
}
