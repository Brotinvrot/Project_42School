/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:39:40 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/16 11:39:29 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_HEADER_H
# define BONUS_HEADER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				number;
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
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
void	*ft_memset(void *dst, int n, size_t len);

// free_memory
void	goto_free(char **str);
void	free_stack(t_Stack *stack);

// stack
void	init_stack(t_Stack *stack);
void	fill_stack(t_Stack *a, char **str);

// checking
void	checking(t_Stack *a, t_Stack *b);
void	exec_instruct(char *line, t_Stack *a, t_Stack *b);
void	error_func(t_Stack *a, t_Stack *b);

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