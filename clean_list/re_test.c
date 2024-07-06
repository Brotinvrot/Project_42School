/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:17:42 by macushka          #+#    #+#             */
/*   Updated: 2024/07/06 12:18:41 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "header_new.h"

// typedef struct  s_node// Это структрура для нодов (хранит число/ указатль на следующий нод и на предыдущий)
// {
//     int             number;
//     struct s_node   *next;
//     struct s_node   *prev;
// }   t_node;

// typedef struct s_stack// 
// {
//     t_node  *top;
//     t_node  *end;
// }   t_Stack;

// void init_stack(t_Stack *stack)// Здесь мы инициализируем его, тоесть делаем оба указателя на NULL
// {
//     stack -> top = NULL;
//     stack -> end = NULL;
// }

// t_node  *create_node(int value)// Маленьки нодики создаются неважно для какого стека. Кто вызвал тот и получит ноду, новую и с переданным значением.
// {
//     t_node  *new_node;

//     new_node = malloc(sizeof(t_node));
//     if (new_node == NULL)
//     {
//         printf ("Memory allocation failed\n");
//         exit (1);
//     }
//     new_node -> number = value;
//     new_node -> next = NULL;
//     new_node -> prev = NULL;
//     return (new_node);
// }

// void push_B(t_Stack *stack_A, t_Stack *stack_B)  перенёс в команды
// {
//     t_node  *tmp;

//     if (stack_A -> top == NULL)
//         return ;
//     tmp = stack_A -> top;
//     stack_A -> top = stack_A -> top -> next;
//     if (stack_A -> top != NULL)
//         stack_A -> top -> prev = NULL;
//     else
//         stack_A -> end = NULL;
//     tmp -> next = stack_B -> top;
//     tmp -> prev = NULL;
//     if (stack_B -> top != NULL)
//         stack_B -> top -> prev = tmp;
//     else
//         stack_B -> end = tmp;
//     stack_B -> top = tmp;
// }

// void push_A(t_Stack *stack_A, t_Stack *stack_B) // Аналогично push_B (возможно придётся удалить принтФ)
// {
//     t_node  *tmp;

//     if (stack_B -> top == NULL)
//         return ;
//     tmp = stack_B -> top;
//     stack_B -> top = stack_B -> top -> next;
//     if (stack_B -> top != NULL)
//         stack_B -> top -> prev = NULL;
//     else
//         stack_B -> end = NULL;
//     tmp -> next = stack_A -> top;
//     tmp -> prev = NULL;
//     if (stack_A -> top != NULL)
//         stack_A -> top -> prev = tmp;
//     else
//         stack_A -> end = tmp;
//     stack_A -> top = tmp;
// }

// void    swap_A(t_Stack *stack_A)
// {
//     if (stack_A -> top == NULL || stack_A -> top -> next == NULL)
//         return ;
//     stack_A -> top -> prev = stack_A -> top -> next;
//     stack_A -> top -> next = stack_A -> top -> next -> next;
//     stack_A -> top -> prev -> next = stack_A -> top;
//     stack_A -> top = stack_A -> top -> prev;
//     stack_A -> top ->prev = NULL;
// }

// void    swap_B(t_Stack *stack_B)
// {
//     if (stack_B -> top == NULL || stack_B -> top -> next == NULL)
//         return ;
//     stack_B -> top -> prev = stack_B -> top -> next;
//     stack_B -> top -> next = stack_B -> top -> next -> next;
//     stack_B -> top -> prev -> next = stack_B -> top;
//     stack_B -> top = stack_B -> top -> prev;
//     stack_B -> top ->prev = NULL;
// }

// void swap_SS(t_Stack *stack_A, t_Stack *stack_B)
// {
//     swap_A(stack_A);
//     swap_B(stack_B);
// }

// void    rotate_A(t_Stack *stack_A)
// {
//     if (stack_A -> top == NULL || stack_A -> top -> next == NULL)
//         return ;
//     stack_A -> top -> prev = stack_A -> end;
//     stack_A -> end -> next = stack_A -> top;
//     stack_A -> top -> next -> prev = NULL;
//     stack_A -> top = stack_A -> top -> next;
//     stack_A -> end = stack_A -> end -> next;
//     stack_A -> end -> next = NULL;
// }

// void    rotate_B(t_Stack *stack_B)
// {
//     if (stack_B -> top == NULL || stack_B -> top -> next == NULL)
//         return ;
//     stack_B -> top -> prev = stack_B -> end;
//     stack_B -> end -> next = stack_B -> top;
//     stack_B -> top -> next -> prev = NULL;
//     stack_B -> top = stack_B -> top -> next;
//     stack_B -> end = stack_B -> end -> next;
//     stack_B -> end -> next = NULL;
// }

// void    rotate_RR(t_Stack *stack_A, t_Stack *stack_B)
// {
//     rotate_A(stack_A);
//     rotate_B(stack_B);
// }

// void    rotate_RA(t_Stack *stack_A)
// {
//     if (stack_A -> top == NULL || stack_A -> top -> next == NULL)
//         return ;
//     stack_A -> end -> next = stack_A -> top;
//     stack_A -> top -> prev = stack_A -> end;
//     stack_A -> end = stack_A -> end -> prev;
//     stack_A -> end -> next = NULL;
//     stack_A -> top = stack_A -> top -> prev;
//     stack_A -> top -> prev = NULL;
// }

// void    rotate_RB(t_Stack *stack_B)
// {
//     if (stack_B -> top == NULL || stack_B -> top -> next == NULL)
//         return ;
//     stack_B -> end -> next = stack_B -> top;
//     stack_B -> top -> prev = stack_B -> end;
//     stack_B -> end = stack_B -> end -> prev;
//     stack_B -> end -> next = NULL;
//     stack_B -> top = stack_B -> top -> prev;
//     stack_B -> top -> prev = NULL;
// }

// void    rotate_RRR(t_Stack *stack_A, t_Stack *stack_B)
// {
//     rotate_RA(stack_A);
//     rotate_RB(stack_B);
// }

// void    print_stack(t_Stack *stack, char stack_name)
// {
//     t_node  *tmp;

//     tmp = stack -> top;
//     printf ("Stack %c:\n", stack_name);
//     while (tmp!= NULL)
//     {
//         printf ("%d \n", tmp -> number);
//         tmp = tmp -> next;
//     }
// }

void    first_step()
{
    
}

int main(void)
{
    t_Stack stack_A;
    t_Stack stack_B;

    init_stack(&stack_A);
    init_stack(&stack_B);

    for (int i = 0; i < 5; i++)
    {
        t_node *new_node;
    
        new_node = create_node(i);
        new_node -> next = stack_A.top;
        if (stack_A.top != NULL)
            stack_A.top -> prev = new_node;
        else
            stack_A.end = new_node;
        stack_A.top = new_node;
    }
    print_stack(&stack_A, 'A');
    print_stack(&stack_B, 'B');

    // Применение операций для тестирования
    push_B(&stack_A, &stack_B);
    print_stack(&stack_A, 'A');
    print_stack(&stack_B, 'B');

    swap_A(&stack_A);
    print_stack(&stack_A, 'A');

    rotate_A(&stack_A);
    print_stack(&stack_A, 'A');

    rev_RA(&stack_A);
    print_stack(&stack_A, 'A');

    rev_RR(&stack_A, &stack_B);
    print_stack(&stack_A, 'A');
    print_stack(&stack_B, 'B');
    return (0);
}
