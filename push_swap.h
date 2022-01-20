/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:38:18 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/21 00:11:15 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_element
{
	int					val;
	struct s_element	*next;
	struct s_element	*prev;
}				t_element;

typedef struct s_list
{
	int					flag;
	int					ra_cnt;
	int					rb_cnt;
	int					pa_cnt;
	int					pb_cnt;
}				t_list;

typedef struct s_program
{
	int					letter;
	int					range;
	int					error;
	int					nbrneg;
}				t_program;

void		DeleteFrontNodeFromCListNode(t_element **head);
int		push2(t_element **stack, int elem);
void	push4(t_element **dest, int val);
void		del_top2(t_element **head);

t_element			*create_list(int val);
t_element			*push(t_element *dest, int val);
t_element			*pop(t_element *dest, t_element **to);
t_element			*del_top(t_element *dest);
t_element			*stack_init(int nb, char **arg, t_program *prgm);

unsigned int		my_strlen(const char *str, t_program *prgm);
int					my_getnbr(char *str, t_program *prgm);
//to_libft
void				my_putstr(char *str);

void				check_stack(t_element *a, t_element *b);

int					error_check(t_program *prgm, int nb, t_element *a);
int					msg_error(char *str);
int					double_check(int nb, t_element *a);

t_element			*sab(t_element *ab, char *name);
void				pab(t_element **ab, t_element **ba, char *com);
void				ss(t_element **a, t_element **b);
t_element			*rab(t_element *ab, char *com);
void				rr(t_element **a, t_element **b);
t_element			*rrab(t_element *ab, char *com);
void				rrr(t_element **a, t_element **b);

void				atob(int r, int flag, t_element **a, t_element **b);
void				btoa(int r, int flag, t_element **a, t_element **b);

int					pivot_sort(int r, t_element *a);
#endif