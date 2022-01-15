/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:05:08 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/15 18:03:43 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	A_to_B(int r, t_element **a, t_element **b);
void	B_to_A(int r, t_element **a, t_element **b);
int		check_sort(int r, t_element *temp);
void check_stack(t_element *a, t_element *b);
int	change_pivot(int r, int p, t_element *ab, char flag);


void	prgm_init(t_program *prgm)
{
	prgm->error = 0;
	prgm->letter = 0;
	prgm->nbrneg = 0;
	prgm->range = 0;
}

int error_check(t_program *prgm, int nb, t_element *a)
{
	if (prgm->letter == 1)
		return (msg_error("Error\nLetter is included.\n"));
	if (prgm->range == 1)
		return (msg_error("Error\nInt range\n"));
	if (double_check(nb, a) == 1)
		return (msg_error("Error\nDouble!\n"));
	return (0);
}

void	B_to_A(int r, t_element **a, t_element **b)
{
	int p;
	int i;
	int rb_cnt;
	int pa_cnt;
	t_element *temp;

	if (r == 0)
		return ;
	else if (r == 1)
	{
		pab(a, b, "pa");
		return ;
	}
	temp = *b;
	rb_cnt = 0;
	pa_cnt = 0;
	i = r - 1;
	while (i-- > 0)
		temp = temp->next;	
	p = temp->val;
	if ((*b)->val < p)
		p = change_pivot(r, p, *b, 'b');
	while (r > 0)
	{
		if ((*b)->val < p)
		{
			*b = rab(*b, "rb");
			rb_cnt++;
		}
		else
		{
			pab(a, b, "pa");
			pa_cnt++;
		}
		r--;
	}
	i = rb_cnt;
	while (i-- > 0)
		*b = rrab(*b, "rrb");
//	check_stack(*a, *b);
	A_to_B(pa_cnt, a, b);
	B_to_A(rb_cnt, a, b);
}

int check_sort(int r, t_element *temp)
{
	while (r > 1)
	{
		if (temp->val > temp->next->val)
			return (0);
		temp = temp->next;
		r--;
	}
	return (1);
}

int	change_pivot(int r, int p, t_element *ab, char flag)
{
	t_element *temp;

	temp = ab;
	if (flag == 'a')
	{
		while (r-- - 1 > 0)
			temp = temp->next;
		r = temp->val;
		temp->val = ab->val;
		ab->val = r;
		p = temp->val;
	}
	if (flag == 'b')
	{
		while (r-- - 1 > 0)
			temp = temp->next;
		r = temp->val;
		temp->val = ab->val;
		ab->val = r; 
		p = temp->val;
	}
	return (p);
}

void	find_maxmin(t_element **a, int *max, int *min)
{
	int	val;

	val = (*a)->val;
	*max = (*a)->val;
	*min = (*a)->val;
	while (1)
	{
		if ((*a)->val > *max)
			*max = (*a)->val;
		if ((*a)->val < *min)
			*min = (*a)->val;
		*a = (*a)->next;
		if (val == (*a)->val)
			break ;
	}
}

int	sort_three(t_element **a)
{
	int max;
	int min;

	if ((*a)->prev->val != (*a)->next->next->val)
		return (0);
	find_maxmin(a, &max, &min);
	if ((*a)->val == min)
	{
		*a = rab(*a, "ra");
		*a = sab(*a, "sa");
		*a = rrab(*a, "rra");
	}
	else if ((*a)->next->val == min)
	{
		if ((*a)->val == max)
			*a = rab(*a, "ra");
		else
			*a = sab(*a, "sa"); 
	}
	else
	{
		if ((*a)->val == max)
		{
			*a = sab(*a, "sa");
			*a = rrab(*a, "rra");
		}
		else
			*a = rrab(*a, "rra");
	}
	return (1);
}

/*
void	sort_three(t_element **a)
{
	int	max;
	int	min;
	
	find_maxmin(a, &max, &min);
	if ((*a)->val == min)
	{
		*a = rab(*a, "ra");
		*a = sab(*a, "sa");
		*a = rrab(*a, "rra");
		return ;
	}
	else if ((*a)->next->val != max)
	*a = sab(*a, "sa");
	*a = rab(*a, "ra");
	*a = sab(*a, "sa");
	*a = rrab(*a, "rra");
	if ((*a)->val != min)
		*a = sab(*a, "sa");
}
*/

void	A_to_B(int r, t_element **a, t_element **b)
{
	int p;
	int i;
	int ra_cnt;
	int pb_cnt;
	t_element *temp;

	if (check_sort(r, *a) == 1)
		return ;
	else if (r == 2)
	{
		if ((*a)->val > (*a)->next->val)
			*a = sab(*a, "sa");
		return ;
	}
	else if (r == 3)
	{
		if (sort_three(a) == 1)
			return ;
	}
	temp = *a;
	ra_cnt = 0;
	pb_cnt = 0;
	i = r - 1;
	while (i-- > 0)
		temp = temp->next;
	p = temp->val;
	if ((*a)->val > p)
		p = change_pivot(r, p, *a, 'a');
	i = r;
	while (i > 0)
	{
		if ((*a)->val >= p)
		{
			if ((*a)->val != p)
			{	
				*a = rab(*a, "ra");	
				ra_cnt++;
			}
		}
		else
		{
			pab(b, a, "pb");
			pb_cnt++;
		}
		i--;
	}
	i = ra_cnt;
//	if (ra_cnt > 1 && j + 1 != ra_cnt)
		while (i-- > 0)
			*a = rrab(*a, "rra");
//	check_stack(*a, *b);
	A_to_B(ra_cnt + 1, a, b); //마지막자리 피봇을 ra 안해주기로 했기에 + 1
	B_to_A(pb_cnt, a, b);
}

void check_stack(t_element *a, t_element *b)
{
	t_element	*temp;
	
	temp = 0;
	printf("A : ");
	temp = a;
	while (1 && temp)
	{
		printf("%d ",temp->val);
		temp = temp->next;
		if ((a)->val == temp->val)
			break;
	}
	printf("\nB : ");
	temp = b;
	while (1 && temp)
	{
		printf("%d ",temp->val);
		temp = temp->next;
		if ((b)->val == temp->val)
			break;
	}
	printf("\n");
}

int	main(int nb, char **arg)
{
	t_element	*a;
	t_element	*b;
	t_program	prgm;

	prgm_init(&prgm);
	a = NULL; //왜? 차이가 없어서 뺐다.
	b = NULL; //왜?? 일단 제거
	a = stack_init(nb, arg, &prgm);
	if (error_check(&prgm, nb, a) == 1)
		return (0);
	A_to_B(nb - 1, &a, &b);
//	check_stack(a, b);
	return (0);
}
