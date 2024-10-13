/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:35:38 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/12 22:29:31 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

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
void	print_stack(t_Stack *stack, char str);
void	goto_free(char **str);
void	push_min_to_b(t_Stack *a, t_Stack *b);
void	sort_stack(t_Stack *a, t_Stack *b);
void	init_stack(t_Stack *stack);
void	fill_stack(t_Stack *a, char **str);
void	rotate_a(t_Stack *a);
void	rotate_b(t_Stack *b);
void	free_stack(t_Stack *stack);
void	rev_ra(t_Stack *a);
void	rev_rb(t_Stack *b);
void	swap_a(t_Stack *a);
void	swap_b(t_Stack *b);
void	swap(t_Stack *stack);
int		check_int(char **str);
int		chek_doubl(char **str);
long	ft_atoi(const char *str);
void	check_simbl(char *str);
short	if_it_sort(t_Stack *stack);
void	test_command(t_Stack *a, t_Stack *b);
t_node	*create_node(int value);
size_t	ft_strlen(const char *str);
int		count_nods(t_Stack *stack);
void	speedrun(t_Stack *a, t_Stack *b);
void	find_min_pb(t_Stack *a, t_Stack *b);
void	rotate_to_min(t_Stack *a, int min, int index_min, int max_index);
void	indexing(t_Stack *stack);
void	fill_ind(t_Stack *stack);
void	print_index(t_Stack *stack);
void	assert_stack(t_Stack *stack);
void	sort_stack_1(t_Stack *a, t_Stack *b);
void	move_min_to_top(t_Stack *stack);
void	rotate_to_max(t_Stack *stack, int max, int index_max, int max_index);
void	move_to_b (t_Stack *a, t_Stack *b);
void	move_to_a(t_Stack *a, t_Stack *b);
void	pre_sort (t_Stack *a, t_Stack *b);
void	recurs_sort_a(t_Stack *a, t_Stack *b);
int		find_max_or_min_index(t_Stack *stack, int flag);
int		ind_median(t_Stack *stack);
//void	rotate_b_to_insert(t_Stack *b, int number);
void	sort_two(t_Stack *a);
void	sort_three(t_Stack *a);
void	pre_sort(t_Stack *a, t_Stack *b);
// CALCULATION
int		best_case(t_Stack *a, t_Stack *b);
int		find_place(t_Stack *a, int index_b);
int		move_to_the_top(t_Stack *stack, int index);
#endif
