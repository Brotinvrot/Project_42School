/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:03:08 by macushka          #+#    #+#             */
/*   Updated: 2024/07/04 20:23:03 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_new.h"

void    rev_RR(t_Stack *stack_A, t_Stack *stack_B)
{
    if (stack_A -> top == NULL || stack_A -> top -> next == NULL)
        return ;
    if (stack_B -> top == NULL || stack_B -> top -> next == NULL)
        return ;
    stack_A -> end -> next = stack_A -> top;
    stack_A -> top -> prev = stack_A -> end;
    stack_A -> end = stack_A -> end -> prev;
    stack_A -> end -> next = NULL;
    stack_A -> top = stack_A -> top -> prev;
    stack_A -> top -> prev = NULL;
    stack_B -> end -> next = stack_B -> top;
    stack_B -> top -> prev = stack_B -> end;
    stack_B -> end = stack_B -> end -> prev;
    stack_B -> end -> next = NULL;
    stack_B -> top = stack_B -> top -> prev;
    stack_B -> top -> prev = NULL;
    write(1, "rrr\n", 4);
}

void    init_stack(t_Stack *stack)
{
    stack -> top = NULL;
    stack -> end = NULL;
}

t_node  *create_node(int value)
{
    t_node  *new_node;

    new_node = malloc(sizeof(t_node));
    if (new_node == NULL)
    {
        printf ("Memory allocation failed\n");
        exit (1);
    }
    new_node -> number = value;
    new_node -> next = NULL;
    new_node -> prev = NULL;
    return (new_node);
}

void    print_stack(t_Stack *stack, char str)
{
    t_node  *tmp;

    tmp = stack -> top;
    printf ("%c\n", str);
    while (tmp!= NULL)
    {
        printf ("%d", tmp -> number);
        tmp = tmp -> next;
    }
    printf ("\n");
}
