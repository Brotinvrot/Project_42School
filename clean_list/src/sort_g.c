/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:38:57 by macushka          #+#    #+#             */
/*   Updated: 2024/10/05 16:31:40 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_new.h"

// int distance_to_end(t_Stack *b, t_node *target)
// {
//     t_node *tmp = b->end;
//     int distance = 0;

//     // Проходим по стеку от конца до целевого элемента
//     while (tmp != target)
//     {
//         tmp = tmp->prev;
//         distance++;
//     }
//     return distance;
// }

// int distance_to_top(t_Stack *b, t_node *target)
// {
//     t_node *tmp = b->top;
//     int distance = 0;

//     // Проходим по стеку от вершины до целевого элемента
//     while (tmp != target)
//     {
//         tmp = tmp->next;
//         distance++;
//     }
//     return distance;
// }

// void rotate_to_insert(t_Stack *b, t_node *target)
// {
//     if (distance_to_top(b, target) < distance_to_end(b, target))
//     {
//         while (b->top != target)
//             rotate_b(b);  // Обычная ротация
//     }
//     else
//     {
//         while (b->top != target)
//             rev_rb(b);  // Реверсная ротация
//     }
// }

// t_node *find_insertion_point(t_Stack *b, int index_a)
// {
//     t_node *tmp = b->top;

//     while (tmp != NULL)
//     {
//         if (tmp->index < index_a && (tmp->next == NULL || tmp->next->index > index_a))
//             return tmp->next;
//         tmp = tmp->next;
//     }
//     return NULL;
// }

void	push_to_b (t_Stack *a, t_Stack *b)
{
	int			index_a;
	t_node		*tmp;
	static int	min_ind;
	static int	max_ind;

	tmp	= b -> top;
	index_a = a -> top -> index;
	if (tmp == NULL)
		push_b (a, b);
	else if (tmp -> next == NULL)
		if (index_a > tmp -> index)
		{
			min_ind = tmp -> index;
			max_ind = index_a;
			push_b (a, b);
		}
		else
		{
			min_ind = index_a;
			max_ind = tmp -> index;
			push_b (a, b);
			swap_b (b);
		}
	else if (index_a > max_ind || index_a < min_ind)
	{
		while (tmp -> index != max_ind)
			rotate_b (b);
		push_b (a, b);
		if (index_a > max_ind)
			max_ind = index_a;
		else
			min_ind = index_a;
	}
	else
	{
		if (count_nods (b) == 2)
		{
			push_b (a, b);
			swap_b (b);
		}
		else
		{
			while (b -> top -> index > index_a && b ->top -> next ->index < index_a)
				rotate_b (b);
			rotate_b (b);
			push_b (a, b);
		}
		sleep(1);
		print_stack (b, 'b');
		print_stack_index (b);
		sleep(1);
	}
	// else  // Если в стеке B больше двух элементов
    // {
    //     t_node *target = find_insertion_point(b, index_a);
    //     if (target)
    //         rotate_to_insert(b, target);  // Выбираем ротацию
    //     push_b(a, b);  // Вставляем элемент
    // }
}

void	assert_stack(t_Stack *stack)
{
	t_node	*top = stack->top;
	t_node	*end = stack->end;
	int		stack_size = 0;
	
	while (top)
	{
		stack_size++;
		top = top->next;
	}
	top = stack->top;
	
	int *arr1 = malloc(stack_size * sizeof(int));
	int *arr2 = malloc(stack_size * sizeof(int));
	int	len1 = 0;
	int	len2 = 0;
	for (int i = 0; i < stack_size; i++)
	{
		if (top)
		{
			len1++;
			arr1[i] = top->number;
			top = top->next;
		}
		if (end)
		{
			len2++;
			arr2[stack_size - i - 1] = end->number;
			end = end->prev;
		}
	}
	if (len1 != len2)
	{
		printf("Error: stack size is different from the beginning and end\n%i != %i\n", len1, len2);
		top = stack->top;
		printf("stack from the beginning:\n");
		while (top)
		{
			printf("%i ", top->number);
			top = top->next;
		}
		end = stack->end;
		printf("stack from the beginning:\n");
		while (end)
		{
			printf("%i ", end->number);
			end = end->prev;
		}
		exit(0);
	}
	for (int i = 0; i < stack_size; i++)
	{
		if (arr1[i] != arr2[i])
		{
			printf("Error: stack is wrong\n");
			exit(0);
		}
	}
}

void	general_sort (t_Stack *a, t_Stack *b)
{
	while (a -> top != NULL)
	{
		push_to_b (a, b);
		print_stack(a, 'a');
		print_stack(b, 'b');
		// assert_stack(a);
		assert_stack(b);
	}
		
	while (b -> top != NULL)
	{
		push_a(a, b);
		print_stack(a, 'a');
		print_stack(b, 'b');
		// assert_stack(a);
		assert_stack(b);
	}
		
}