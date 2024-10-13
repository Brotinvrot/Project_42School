/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strong_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:38:46 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/13 07:46:04 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// эта функция принимает указатель на стек и идекс определённой ноды из стека А
// затем выбирает кратчайший путк к ТОПУ стека, используя реверсивный ротейд или просто ротацию

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

int	find_max_or_min_index(t_Stack *stack, int flag)
{
	t_node	*tmp;
	int		index;

	tmp = stack -> top;
	index = stack -> top -> index;
	if (flag == 1)
	{
		while (tmp != NULL)
		{
			if (index < tmp -> index)
				index = tmp -> index;
			tmp = tmp -> next;
		}
	}
	else
	{
		while (tmp != NULL)
		{
			if (index > tmp -> index)
				index = tmp -> index;
			tmp = tmp -> next;
		}
	}
	return (index);
}

void	move_to_a(t_Stack *a, t_Stack *b)
{
	int	max_index = find_max_or_min_index(a, 1);
	int	min_index = find_max_or_min_index(a, -1);

	while (b -> top != NULL)
	{
		if (a -> top == NULL)
		{
			push_a(a, b);
			push_a(a, b);
			if (a -> top -> index < a -> top -> next -> index)
				swap_a (a);
			max_index = b -> top -> index;
			min_index = b -> top -> next -> index;
		}
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

void move_min_to_top(t_Stack *stack)// начинаю ковырять, меняю максимум на минимум
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

void	r_or_rr_new(t_Stack *stack, int index)
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
		rev_rb (stack);
		return ;
	}
	while (tmp -> index != index && tmp != NULL)
	{
		from_the_end++;
		tmp = tmp -> prev;
	}
	if (from_the_top < from_the_end)
		while (stack -> top -> index != index)
			rotate_b(stack);
	else
		while (stack -> top -> index != index)
			rev_rb(stack);
}

void	find_best_place_new(t_Stack *a, t_Stack *b, int max_index)
{
	int		current_index;
	t_node	*tmp;

	current_index = best_case(a, b);
	tmp = a -> top;
	while (tmp != NULL)
	{
		if (tmp -> index > current_index && tmp -> index < max_index)
			max_index = tmp -> index;
		tmp = tmp -> next;
	}
	r_or_rr_new(b, current_index);
	r_or_rr(a, max_index);
	push_a (a, b);

}

void	sort_stack_1(t_Stack *a, t_Stack *b)// кашу тут заварил
{
	//move_to_a(a, b);
	while (b -> top != NULL)
		find_best_place_new(a, b, find_max_or_min_index(a, 1));
	r_or_rr(a, find_max_or_min_index(a, -1));
	//move_min_to_top(a);
}