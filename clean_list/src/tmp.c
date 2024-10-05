
void rotate_b_to_insert(t_Stack *b, int number)
{
	t_node	*tmp;
	int		coinc_num;

	tmp = b -> top;
	if (tmp == NULL)
		return ;
	while (tmp -> next != NULL)
	{
		// Если нашли место: tmp->number больше, а tmp->next->number меньше
		if (tmp -> number > number && tmp -> next -> number < number)
		{
			coinc_num = tmp -> next -> number;
			// Делаем ротации до тех пор, пока tmp->next не окажется на вершине
			while (b -> top -> number != coinc_num)
			{
				write (1, "Nashel\n", 7);
				rotate_b (b);
			}
			write (1, "Wishel iz zikla\n", 16);
			return ;
		}
		tmp = tmp -> next;
	}
}

void	move_to_b (t_Stack *a, t_Stack *b)
{
	while (a -> top != NULL)
	{
		if (b -> top == NULL)
		{
			push_b(a, b);
			push_b(a, b);
			sort_two (b);
			print_stack (b, 'b');
			sleep(1);
		}
		else if (b -> top -> next -> next != NULL)
		{
			rotate_b_to_insert(b, a -> top -> number);
			print_stack (b, 'b');
			sleep(1);
			push_b(a, b);
			print_stack (b, 'b');
		}
		else if (a -> top -> number < b -> end -> number)
		{
			push_b(a, b);
			rotate_b(b);
			print_stack (b, 'b');
			sleep(1);
		}
		else if (a -> top -> number > b -> top -> number)
		{
			push_b (a, b);
			print_stack (b, 'b');
			sleep(1);
		}
	}
}

void	rotate_to_max(t_Stack *b, int max, int index_max, int max_index)
{
	if (index_max > (max_index - index_max - 1))
	{
		while (b -> top -> number != max)
		{
			rev_rb (b);
			if (if_it_sort (b) == 0)
				return ;
		}
	}
	else
	{
		while (b -> top -> number != max)
		{
			rotate_b(b);
			if (if_it_sort (b) == 0)
				return ;
		}
	}
}

void	move_max_to_top(t_Stack *b)
{
	t_node	*tmp;
	int		max;
	int		max_index;
	int		index_max;

	tmp = b -> top;
	max = tmp -> number;
	max_index = 0;
	index_max = 0;
	while (tmp != NULL)
	{
		if (tmp -> number > max)
		{
			max = tmp -> number;
			index_max = max_index;
		}
		tmp = tmp -> next;
		max_index++;
	}
	rotate_to_max (b, max, index_max, max_index);
}

void	sort_stack_1(t_Stack *a, t_Stack *b)
{
	move_to_b(a, b);
	print_stack (b, 'b');
	move_max_to_top(b);
	while (b -> top != NULL)
		push_a(a, b);
}

< Old almost works algoritm >


