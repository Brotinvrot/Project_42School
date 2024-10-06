// void	push_b(t_Stack *a, t_Stack *b)
// {
// 	t_node	*tmp;

// 	if (a -> top == NULL)
// 		return ;
// 	tmp = a -> top;
// 	if (tmp -> next == NULL)
// 	{
// 		a -> top = NULL;
// 		a -> end = NULL;
// 	}
// 	else
// 	{
// 		a -> top = a -> top -> next;
// 		a -> top -> prev = NULL;
// 	}
// 	if (b -> top == NULL)
// 	{
// 		b -> top = tmp;
// 		b -> end = tmp;
// 		b -> top -> prev = NULL;
// 		b -> end -> next = NULL;
// 	}
// 	else
// 	{
// 		tmp -> next = b -> top;
// 		b -> top -> prev = tmp;
// 		b -> top = tmp;
// 	}
// 	write (1, "pb\n", 3);
// }