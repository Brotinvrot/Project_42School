/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:10:09 by macushka          #+#    #+#             */
/*   Updated: 2024/07/04 20:10:00 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_new.h"

void    rotate_A(t_Stack *stack_A)
{
    if (stack_A -> top == NULL || stack_A -> top -> next == NULL)
        return ;
    stack_A -> top -> prev = stack_A -> end;
    stack_A -> end -> next = stack_A -> top;
    stack_A -> top -> next -> prev = NULL;
    stack_A -> top = stack_A -> top -> next;
    stack_A -> end = stack_A -> end -> next;
    stack_A -> end -> next = NULL;
    write (1, "ra\n", 3);
}

void    rotate_B(t_Stack *stack_B)
{
    if (stack_B -> top == NULL || stack_B -> top -> next == NULL)
        return ;
    stack_B -> top -> prev = stack_B -> end;
    stack_B -> end -> next = stack_B -> top;
    stack_B -> top -> next -> prev = NULL;
    stack_B -> top = stack_B -> top -> next;
    stack_B -> end = stack_B -> end -> next;
    stack_B -> end -> next = NULL;
    write (1, "rb\n", 3);
}

void    rotate_R(t_Stack *stack_A, t_Stack *stack_B)
{
    if (stack_A -> top == NULL || stack_A -> top -> next == NULL)
        return ;
    if (stack_B -> top == NULL || stack_B -> top -> next == NULL)
        return ;
    stack_A -> top -> prev = stack_A -> end;
    stack_A -> end -> next = stack_A -> top;
    stack_A -> top -> next -> prev = NULL;
    stack_A -> top = stack_A -> top -> next;
    stack_A -> end = stack_A -> end -> next;
    stack_A -> end -> next = NULL;
    stack_B -> top -> prev = stack_B -> end;
    stack_B -> end -> next = stack_B -> top;
    stack_B -> top -> next -> prev = NULL;
    stack_B -> top = stack_B -> top -> next;
    stack_B -> end = stack_B -> end -> next;
    stack_B -> end -> next = NULL;
    write (1, "rr\n", 3);
}

void    rev_RA(t_Stack *stack_A)
{
    if (stack_A -> top == NULL || stack_A -> top -> next == NULL)
        return ;
    stack_A -> end -> next = stack_A -> top;
    stack_A -> top -> prev = stack_A -> end;
    stack_A -> end = stack_A -> end -> prev;
    stack_A -> end -> next = NULL;
    stack_A -> top = stack_A -> top -> prev;
    stack_A -> top -> prev = NULL;
    write (1, "rra\n", 4);
}

void    rev_RB(t_Stack *stack_B)
{
    if (stack_B -> top == NULL || stack_B -> top -> next == NULL)
        return ;
    stack_B -> end -> next = stack_B -> top;
    stack_B -> top -> prev = stack_B -> end;
    stack_B -> end = stack_B -> end -> prev;
    stack_B -> end -> next = NULL;
    stack_B -> top = stack_B -> top -> prev;
    stack_B -> top -> prev = NULL;
    write (1, "rrb\n", 4);
}
