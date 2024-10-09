/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strong_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:38:46 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/09 12:00:58 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void rotate_b_to_insert(t_Stack *b, int number)
// {
//     t_node *tmp;
//     int coinc_num;

//     tmp = b->top;
//     if (tmp == NULL)
//         return;

//     // Ищем место для вставки элемента
//     while (tmp->next != NULL)
//     {
//         // Если нашли место, где элемент подходит по величине между двумя элементами
//         if (tmp->number > number && tmp->next->number < number)
//         {
//             coinc_num = tmp->next->number;
//             while (b->top->number != coinc_num)
//                 rotate_b(b);  // Ротация до нужного элемента
//             return;
//         }
//         tmp = tmp->next;
//     }

//     // Если не нашли подходящего места, нужно учесть крайние случаи
//     if (number > b->top->number || number < b->end->number)
//     {
//         // Если число больше максимума или меньше минимума, делаем ротацию к концу
//         while (b->top->number != b->end->number)
//             rotate_b(b);
//     }
// }
void	r_or_rr(t_Stack *stack, int index)
{
	t_node	*tmp;
	int		from_the_top;
	int		from_the_end;

	from_the_top = 0;
	from_the_end = 0;
	tmp	= stack -> top;
	if (tmp -> index == index)
		return ;
	while (tmp -> index != index && tmp != NULL)
	{
		from_the_top++;
		tmp = tmp -> next;
	}
	tmp = stack -> end;
	if (tmp -> index == index)
	{
		rev_ra (stack);
		return ;
	}
	while (tmp -> index != index && tmp != NULL)
	{
		from_the_end++;
		tmp = tmp -> prev;
	}
	if (from_the_top < from_the_end)
		while (stack -> top -> index != index)
			rotate_a(stack);
	else
		while (stack -> top -> index != index)
			rev_ra(stack);
}

void	find_best_place(t_Stack *a, t_Stack *b, int max_index)
{
	int		current_index;
	t_node	*tmp;

	current_index = b -> top -> index;
	tmp = a -> top;
	while (tmp != NULL)
	{
		if (tmp -> index > current_index && tmp -> index < max_index)
			max_index = tmp -> index;
		tmp = tmp -> next;
	}
	r_or_rr(a, max_index);
	push_a (a, b);
}

void	move_to_a(t_Stack *a, t_Stack *b)
{
	int	max_index = a -> end -> index;
	int	min_index = a -> top -> index;

	while (b -> top != NULL)
	{
		// if (a -> top == NULL)
		// {
		// 	push_a(a, b);
		// 	push_a(a, b);
		// 	if (a -> top -> index < a -> top -> next -> index)
		// 		swap_a (a);
		// 	max_index = b -> top -> index;
		// 	min_index = b -> top -> next -> index;
		// }
		if (b -> top -> index > max_index || b -> top -> index < min_index)
		{
			if (a -> top -> index != min_index)
				r_or_rr(a, min_index);
			if (b -> top -> index > max_index)
				max_index = b -> top -> index;
			else
				min_index = b -> top -> index;
			push_a(a, b);
		}
		else
			find_best_place(a, b, max_index);
	}
}

void rotate_to_max(t_Stack *stack, int max, int index_max, int max_index)
{
    if (index_max > (max_index - index_max - 1))
    {
        while (stack -> top -> number != max)
        {
            rev_ra(stack);
            if (if_it_sort(stack) == 0)  // Прерываем, если стек отсортирован
                return;
        }
    }
    else
    {
        while (stack -> top -> number != max)
        {
            rotate_a(stack);
            if (if_it_sort(stack) == 0)  // Прерываем, если стек отсортирован
                return;
        }
    }
}

void move_min_to_top(t_Stack *stack)
{
    t_node *tmp;
    int max;
    int max_index;
    int index_max;

    if (stack -> top == NULL)  // Проверка на случай пустого стека
        return;
    tmp = stack -> top;
    max = tmp->number;
    max_index = 0;
    index_max = 0;

    // Поиск максимального элемента в стеке B
    while (tmp != NULL)
    {
        if (tmp->number > max)
        {
            max = tmp->number;
            index_max = max_index;
        }
        tmp = tmp->next;
        max_index++;
    }

    // Ротация стека B до максимального элемента
    rotate_to_max(stack, max, index_max, max_index);
}

void	sort_stack_1(t_Stack *a, t_Stack *b)
{
	move_to_a(a, b);
	print_stack (b, 'b');
	print_stack (a, 'a');
	move_min_to_top(a);
	while (b -> top != NULL)
		push_a(a, b);
}