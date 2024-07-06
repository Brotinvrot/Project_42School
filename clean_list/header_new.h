/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_new.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:39:30 by macushka          #+#    #+#             */
/*   Updated: 2024/07/04 20:14:19 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_NEW
#define HEADER_NEW

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct  s_node
{
    int             number;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct s_stack
{
    t_node  *top;
    t_node  *end;
}   t_Stack;

void    rev_RR(t_Stack *stack_A, t_Stack *stack_B);
void    rotate_R(t_Stack *stack_A, t_Stack *stack_B);
void    push_B(t_Stack *stack_A, t_Stack *stack_B);
void    push_A(t_Stack *stack_A, t_Stack *stack_B);
void    swap_SS(t_Stack *stack_A, t_Stack *stack_B);
void    init_stack(t_Stack *stack);
void    print_stack(t_Stack *stack, char str);
void    rotate_A(t_Stack *stack_A);
void    rotate_B(t_Stack *stack_B);
void    rev_RA(t_Stack *stack_A);
void    rev_RB(t_Stack *stack_B);
void    swap_A(t_Stack *stack_A);
void    swap_B(t_Stack *stack_B);
t_node  *create_node(int value);

#endif
