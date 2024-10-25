/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/10/13 14:44:44 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/15 13:11:07 by drabadan         ###   ########.fr       */
=======
/*   Created: 2024/10/01 13:35:38 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/12 22:29:31 by drabadan         ###   ########.fr       */
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

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

// main
void	first_step(int argc, char **argv);
void	second_step(char **str);

// all chekc
void	check_simbl(char *str);
short	if_it_sort(t_Stack *stack);
int		chek_doubl(char **str);
int		check_int(char **str);

// function library
char	*ft_strdup(const char *src);
char	**ft_split(char **argv, int argc, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

// support function library
int		total_length(int argc, char **argv);
int		word_counter(char const *s, char c);
char	*str_creat(char *str, int argc, char **argv);
void	put(char const *s, char c, char **result);
long	ft_atoi(const char *str);

// support function library 2
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);

// free_memory
void	goto_free(char **str);
void	free_stack(t_Stack *stack);

// stack
void	init_stack(t_Stack *stack);
void	fill_stack(t_Stack *a, char **str);

// nods
void	init_index(t_Stack *stack);
void	fill_ind(t_Stack *stack);

// sort
void	sort_stack(t_Stack *a, t_Stack *b);
void	greedy_sort(t_Stack *a, t_Stack *b);
void	find_best_place_new(t_Stack *a, t_Stack *b, int max_index);
void	r_or_rr_stack_a(t_Stack *stack, int index);
void	r_or_rr_stack_b(t_Stack *stack, int index);

// calculation
int		best_case(t_Stack *a, t_Stack *b);
int		move_to_the_top(t_Stack *stack, int index);
int		find_place(t_Stack *a, int index_b);
int		find_max_or_min_index(t_Stack *stack, int flag);

// pre sort and median sort
void	pre_sort(t_Stack *a, t_Stack *b);
void	recurs_sort_a(t_Stack *a, t_Stack *b);
int		find_median(t_Stack *stack);
int		count_nods(t_Stack *stack);

// support fast sort
void	find_min_pb(t_Stack *a, t_Stack *b);
void	rotate_to_min(t_Stack *a, int min, int index_min, int max_index);
<<<<<<< HEAD

// fast sort
void	speedrun(t_Stack *a, t_Stack *b);
void	sort_two(t_Stack *stack);
void	sort_three(t_Stack *a);
void	sort_four(t_Stack *a, t_Stack *b);
void	sort_few(t_Stack *a, t_Stack *b);

// comands
void	push_a(t_Stack *a, t_Stack *b);
void	push_b(t_Stack *a, t_Stack *b);
void	swap_a(t_Stack *a);
void	swap_b(t_Stack *b);
void	swap_ss(t_Stack *a, t_Stack *b);
void	rotate_a(t_Stack *a);
void	rotate_b(t_Stack *b);
void	rotate_r(t_Stack *a, t_Stack *b);
void	rev_ra(t_Stack *a);
void	rev_rb(t_Stack *b);
void	rev_rr(t_Stack *a, t_Stack *b);
#endif
=======
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
>>>>>>> b49bc84b014baac541d03cc503a533dd9b7852b3
