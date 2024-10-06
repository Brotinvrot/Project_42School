/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:38:57 by macushka          #+#    #+#             */
/*   Updated: 2024/10/05 21:52:17 by drabadan         ###   ########.fr       */
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
			printf("before swap\n");
			assert_stack(b);
			swap_b (b);
			printf("after swap\n");
			assert_stack(b);
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
	int		stack_size1 = 0;
	int		stack_size2 = 0;
	
	while (top)
	{
		stack_size1++;
		top = top->next;
	}
	while (end)
	{
		stack_size2++;
		end = end->prev;
	}
	if (stack_size1 != stack_size2)
	{
		printf("Error: stack size is different from the beginning and end\n%i != %i\n", stack_size1, stack_size2);
		top = stack->top;
		printf("stack from the beginning:");
		while (top)
		{
			printf(" %i", top->number);
			top = top->next;
		}
		printf("\n");
		end = stack->end;
		printf("stack from the end:");
		while (end)
		{
			printf(" %i", end->number);
			end = end->prev;
		}
		printf("\n");
		exit(0);
	}
	top = stack->top;
	end = stack->end;

	int *arr1 = malloc(stack_size1 * sizeof(int));
	int *arr2 = malloc(stack_size2 * sizeof(int));
	int	len1 = 0;
	int	len2 = 0;
	for (int i = 0; i < stack_size1; i++)
	{
		if (top)
		{
			len1++;
			arr1[i] = top->number;
			// printf("From the beginning:\nelem = %i\nindex = %i\n", arr1[i]);
			top = top->next;
		}
		if (end)
		{
			len2++;
			arr2[stack_size2 - i - 1] = end->number;
			end = end->prev;
		}
	}
	for (int i = 0; i < stack_size1; i++)
	{
		if (arr1[i] != arr2[i])
		{
			printf("Error: stack is wrong\nlen1 = %i, len2 = %i\n", len1, len2);
			top = stack->top;
			printf("stack from the beginning:\n");
			while (top)
			{
				printf("%i ", top->number);
				top = top->next;
			}
			printf("\n");
			end = stack->end;
			printf("stack from the end:\n");
			while (end)
			{
				printf("%i ", end->number);
				end = end->prev;
			}
			printf("\n");
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
		// assert_stack(b);
	}
		
	while (b -> top != NULL)
	{
		push_a(a, b);
		print_stack(a, 'a');
		print_stack(b, 'b');
		// assert_stack(a);
		// assert_stack(b);
	}
		
}