/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_code2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:42:57 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/07 21:19:55 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_to_min(t_Stack *a, int min, int index_min, int max_index)
{
	if (index_min > (max_index - index_min - 1))
	{
		while (a -> top -> number != min)
		{
			rev_ra (a);
			if (if_it_sort (a) == 0)
				return ;
		}
	}
	else
	{
		while (a -> top -> number != min)
		{
			rotate_a(a);
			if (if_it_sort (a) == 0)
				return ;
		}
	}
}

void	find_min_pb(t_Stack *a, t_Stack *b)
{
	t_node	*tmp;
	int		min;
	int		max_index;
	int		index_min;

	tmp = a -> top;
	min = tmp -> number;
	max_index = 0;
	index_min = 0;
	while (tmp != NULL)
	{
		if (tmp -> number < min)
		{
			min = tmp -> number;
			index_min = max_index;
		}
		tmp = tmp -> next;
		max_index++;
	}
	rotate_to_min (a, min, index_min, max_index);
	push_b (a, b);
}

void	sort_two(t_Stack *stack)
{
	if (stack -> top -> number > stack -> end -> number)
		swap_a(stack);
}

void	sort_three(t_Stack *a)
{
	int	top;
	int	midl;
	int	end;

	top = a -> top -> number;
	midl = a -> top -> next -> number;
	end = a -> end -> number;

	if (top > midl && midl > end)//C B A
	{
		swap_a (a);
		rev_ra (a);
	}
	else if (top > end && end > midl)// C A B
		rotate_a (a);
	else if (midl < top && top < end)// B A C
		swap_a (a);
	else if (midl > top && top > end)// B C A
		rev_ra (a);
	else if (top < end && end < midl)// A C B
	{
		swap_a (a);
		rotate_a (a);
	}
}

void	sort_four(t_Stack *a, t_Stack *b)
{
	find_min_pb(a, b);
	if (if_it_sort(a) == 0 && b -> top == NULL)
		return ;
	sort_three(a);
	push_a(a, b);
}

void	sort_few(t_Stack *a, t_Stack *b)
{
	find_min_pb(a, b);
	if (if_it_sort(a) == 0 && b -> top == NULL)
		return ;
	find_min_pb(a, b);
	if (if_it_sort(a) == 0 && b -> top == NULL)
		return ;
	sort_three(a);
	push_a(a, b);
	push_a(a, b);
}

int	count_nods(t_Stack *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack -> top;
	while (tmp != NULL)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}

void	speedrun(t_Stack *a, t_Stack *b)
{
	int	nods;

	nods = count_nods(a);
	if (nods > 5)
		return ;
	if (nods == 2)
		sort_two(a);
	else if (nods == 3)
		sort_three(a);
	else if (nods == 4)
		sort_four(a, b);
	else if (nods == 5)
		sort_few(a, b);
	print_stack (a, 'a');
	if (if_it_sort(a) == 0)
	{
		write (1, "Sort\n", 5);
		free_stack(a);
		free_stack(b);
		exit (0);
	}
	else
		write (1, "Ne sort\n", 8);
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

void	test_command(t_Stack *a, t_Stack *b)
{
	for (int i = 0; i < 2; i++)
	{
		push_b (a, b);
		print_stack(a, 'a');
		print_stack(b, 'b');
	}
	swap_a (a);
	swap_b (b);
	print_stack(a, 'a');
	print_stack(b, 'b');
	swap_ss(a, b);
	sleep(1);
	print_stack(a, 'a');
	sleep(1);
	print_stack(b, 'b');
	for (int i = 0; i < 10; i++)
	{
		printf("BEFORE ROTATE A:\n");
		assert_stack(a);
		assert_stack(b);
		rotate_a(a);
		printf("AFTER ROTATE A:\n");
		assert_stack(a);
		assert_stack(b);
		print_stack(a, 'a');
		print_stack(b, 'b');
		printf("BEFORE ROTATE B:\n");
		assert_stack(a);
		assert_stack(b);
		rotate_b(b);
		assert_stack(a);
		assert_stack(b);
		printf("AFTER ROTATE B:\n");
		print_stack(a, 'a');
		print_stack(b, 'b');
	}
	for (int i = 0; i < 10; i++)
	{
		rev_rr(a, b);
		print_stack(a, 'a');
		print_stack(b, 'b');
	}
	for (int i = 0; i < 10; i++)
	{
		rotate_r(a, b);
		print_stack(a, 'a');
		print_stack(b, 'b');
	}
	for (int i = 0; i < 10; i++)
	{
		swap_a(a);
		swap_b(b);
		print_stack(a, 'a');
		print_stack(b, 'b');
		swap_ss (a, b);
		print_stack(a, 'a');
		print_stack(b, 'b');
	}
	for (int i = 0; i < 10; i++)
	{
		push_b(a, b);
		print_stack(a, 'a');
		print_stack(b, 'b');
		swap_b(b);
		print_stack(a, 'a');
		print_stack(b, 'b');
		swap_ss (a, b);
		print_stack(a, 'a');
		print_stack(b, 'b');
	}
	for (int i = 0; i < 10; i++)
	{
		push_a(a, b);
		print_stack(a, 'a');
		print_stack(b, 'b');
		swap_b(b);
		print_stack(a, 'a');
		print_stack(b, 'b');
		swap_ss (a, b);
		print_stack(a, 'a');
		print_stack(b, 'b');
	}
}
