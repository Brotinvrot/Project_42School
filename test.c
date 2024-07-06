/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:01:02 by drabadan          #+#    #+#             */
/*   Updated: 2024/07/04 18:39:20 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heder.h"

void	print_list(struct s_node *p)
{
	while (p != NULL)
	{
		printf ("%d\n", p->data);
		p = p->next;
	}
}

struct s_node	*create_list(int n, char **str, Our_freedom *freedom)
{
	struct s_node	*current;
	struct s_node	*next;
	struct s_node	*head;
	struct s_node	*temp;
	struct s_node	*p;
	int				i;

	i = 0;
	if (n <= 0)
		return (NULL);
	head = malloc(sizeof(struct s_node));
	if (head == NULL)
	{
		printf ("memory allocation failed\n");
		return (NULL);
	}
	head->data = ft_atoi(str[i], freedom);
	head->next = NULL;
	head -> prev = NULL;
	temp = head;
	i = 1;
	while (i < n)
	{
		p = malloc(sizeof(struct s_node));
		if (p == NULL)
		{
			printf ("memory allocation failed\n");
			current = head;
			while (current != NULL)
			{
				next = current->next;
				free(current);
				current = next;
			}
			return (NULL);
		}
		p -> data = ft_atoi(str[i], freedom);
		p -> next = NULL;
		p -> prev = temp;
		temp->next = p;
		temp = p;
		i++;
	}
	return (head);
}
