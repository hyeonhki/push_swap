/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:05:08 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/13 13:42:51 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	A_to_B(int r, t_element **a, t_element **b);
void	B_to_A(int r, t_element **a, t_element **b);


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
	if (r == 1)
	{
		//printf("\nB, r == 1 pa\n");
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
	//printf("\nB_to_A, r : %d, p : %d\n",r,p);
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
	temp = *a;
	printf("A : ");
	while (1 && temp)
	{
		printf("%d ",temp->val);
		temp = temp->next;
		if ((*a)->val == temp->val)
			break;
	}
	printf("\nB : ");
	temp = *b;
	while (1 && temp)
	{
		printf("%d ",temp->val);
		temp = temp->next;
		if ((*b)->val == temp->val)
			break;
	}
	printf("\n");
	A_to_B(pa_cnt, a, b);
	B_to_A(rb_cnt, a, b);
}

void	A_to_B(int r, t_element **a, t_element **b)
{
	int p;
	int i;
	int ra_cnt;
	int pb_cnt;
	t_element *temp;

	if (r == 1 || r == 0)
	{
		//printf("\nA r == 1 end\n");
		return ;
	}
	else if (r == 2)
	{
		if ((*a)->val > (*a)->next->val)
		{
			i = (*a)->next->val;
			(*a)->next->val = (*a)->val;
			(*a)->val = i;
		}
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
	{
		i = r;
		temp = *a;
		while (i - 1 > 0)
		{
			temp = temp->next;
			i--;
		}
		i = temp->val;
		temp->val = (*a)->val;
		(*a)->val = i;
		p = temp->val;
	}
	i = r;
	while (i > 0)
	{
		if ((*a)->val >= p)
		{
			*a = rab(*a, "ra");
			ra_cnt++;
		}
		else
		{
			pab(b, a, "pb");
			pb_cnt++;
		}
		i--;
	}
	i = ra_cnt;
	while (i-- > 0)
		*a = rrab(*a, "rra");
	/*
	if (pb_cnt == 0)
	{
		i = r;
		temp = *a;
		while (i - 1 > 0)
		{
			temp = temp->next;
			i--;
		}
		i = temp->val;
		temp->val = (*a)->val;
		(*a)->val = i;
	}
	*/
	temp = *a;
	printf("A : ");
	while (1 && temp)
	{
		printf("%d ",temp->val);
		temp = temp->next;
		if ((*a)->val == temp->val)
			break;
	}
	printf("\nB : ");
	temp = *b;
	while (1 && temp)
	{
		printf("%d ",temp->val);
		temp = temp->next;
		if ((*b)->val == temp->val)
			break;
	}
	printf("\n");
	A_to_B(ra_cnt, a, b);
	B_to_A(pb_cnt, a, b);
}

int	main(int nb, char **arg)
{
	t_element	*a;
	t_element	*b;
	t_program	prgm;
	t_element	*temp;

	prgm_init(&prgm);
	a = NULL; //왜? 차이가 없어서 뺐다.
	b = NULL; //왜?? 일단 제거
	a = stack_init(nb, arg, &prgm);
	if (error_check(&prgm, nb, a) == 1)
		return (0);
	A_to_B(nb - 1, &a, &b);
//	A_to_B(4, &a, &b);
//	A_to_B(4, &a, &b);
//	B_to_A(9, &a, &b);
//	A_to_B(2, &a, &b);
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
	return (0);
}
