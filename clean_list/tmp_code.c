
void	push_b(t_Stack *a, t_Stack *b) // Более подробная функция Пуш Б, но длиная
{
	t_node	*tmp;

	if (a -> top == NULL)
		return ;
	tmp = a -> top;
	if (tmp -> next == NULL)
	{
		a -> top = NULL;
		a -> end = NULL;
	}
	else
	{
		a -> top = a -> top -> next;
		a -> top -> prev = NULL;
	}
	if (b -> top == NULL)
	{
		b -> top = tmp;
		b -> end = tmp;
		b -> top -> prev = NULL;
		b -> end -> next = NULL;
	}
	else
	{
		tmp -> next = b -> top;
		b -> top -> prev = tmp;
		b -> top = tmp;
	}
	write (1, "pb\n", 3);
}

void	push_min_to_b(t_Stack *a, t_Stack *b) // функция для нахождения мин значения в А и отправка в Б
{
	t_node	*min;
	t_node	*current;

	min = a -> top;
	current = a -> top;
	while (current != NULL)
	{
		if (current -> number < min -> number)
			min = current;
		current = current -> next;
	}
	while (a -> top != min)
		rotate_a(a);
	push_b (a, b);
}

void	recurs_sort_a(t_Stack *a, t_Stack *b) // рекурсивная функция для сортировки стека А до тех пор пока не останется 3 или 2 элемента
{
	int	median;
	int	first_left_index;

	first_left_index = -1;
	if (count_nods(a) <= 3)
		return ;
	median = find_median(a);
	while (a -> top != NULL && a -> top -> index != first_left_index)
	{
		if (a -> top -> index < median)
			push_b (a, b);
		else
		{
			if (first_left_index == -1)
				first_left_index = a -> top -> index;
			rotate_a (a);
		}
	}
	recurs_sort(a, b);
}

void rotate_b_to_insert(t_Stack *b, int number)
{
    t_node *tmp;
    int coinc_num;

    tmp = b->top;
    if (tmp == NULL)
        return;

    // Ищем место для вставки элемента
    while (tmp->next != NULL)
    {
        // Если нашли место, где элемент подходит по величине между двумя элементами
        if (tmp->number > number && tmp->next->number < number)
        {
            coinc_num = tmp->next->number;
            while (b->top->number != coinc_num)
                rotate_b(b);  // Ротация до нужного элемента
            return;
        }
        tmp = tmp->next;
    }

    // Если не нашли подходящего места, нужно учесть крайние случаи
    if (number > b->top->number || number < b->end->number)
    {
        // Если число больше максимума или меньше минимума, делаем ротацию к концу
        while (b->top->number != b->end->number)
            rotate_b(b);
    }
}
