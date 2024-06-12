/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trening.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:20:23 by drabadan          #+#    #+#             */
/*   Updated: 2024/06/09 13:11:07 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_List
{
	int				data;
	struct s_List	*next;
}	t_Node;

void	print_list(t_Node *head)
{
	t_Node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf ("%d -> ", tmp->data);
		tmp = tmp->next;
	}
	printf ("NULL\n");
}

int	main(void)
{
	t_Node	*head;
	t_Node	*second;
	t_Node	*third;
	t_Node	*tmp;

	head = malloc(sizeof(t_Node));
	second = malloc(sizeof(t_Node));
	third = malloc(sizeof(t_Node));
	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;
	print_list(head);
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (0);
}
