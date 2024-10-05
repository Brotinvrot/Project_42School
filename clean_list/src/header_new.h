/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_new.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macushka <macushka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:35:38 by macushka          #+#    #+#             */
/*   Updated: 2024/10/04 22:26:09 by macushka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_NEW_H
# define HEADER_NEW_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				number;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*end;
}	t_Stack;

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*str_creat(char *str, int argc, char **argv);
void	put(char const *s, char c, char **result);
int		word_counter(char const *s, char c);
char	**ft_split(char **argv, int argc, char c);
char	*ft_strdup(const char *src);
int		total_length(int argc, char **argv);
void	rev_rr(t_Stack *a, t_Stack *b);
void	rotate_r(t_Stack *a, t_Stack *b);
void	push_b(t_Stack *a, t_Stack *b);
void	push_a(t_Stack *a, t_Stack *b);
void	swap_ss(t_Stack *a, t_Stack *b);
void	first_step(int argc, char **argv);
void	print_stack(t_Stack *stack, char c);
void	find_min_pb(t_Stack *a, t_Stack *b);
void	general_sort (t_Stack *a, t_Stack *b);
void	goto_free(char **str);
void	sort_stack(t_Stack *a, t_Stack *b);
void	init_stack(t_Stack *stack);
void	fill_stack(t_Stack *a, char **str);
void	rotate_a(t_Stack *a);
void	rotate_b(t_Stack *b);
void	free_stack(t_Stack *stack);
void	speedrun(t_Stack *a, t_Stack *b);
void	sort_two(t_Stack *a);
void	sort_three(t_Stack *a);
void	sort_four(t_Stack *a, t_Stack *b);
void	sort_few(t_Stack *a, t_Stack *b);
void	rev_ra(t_Stack *a);
void	rev_rb(t_Stack *b);
void	swap_a(t_Stack *a);
void	swap_b(t_Stack *b);
short	if_it_sort(t_Stack *a);
int		check_int(char **str);
int		count_nods(t_Stack *stack);
int		chek_doubl(char **str);
long	ft_atoi(const char *str);
void	check_simbl(char *str);
t_node	*create_node(int value);
size_t	ft_strlen(const char *str);
void	print_stack_index(t_Stack *stack);

#endif
