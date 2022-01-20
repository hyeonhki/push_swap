/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:02:11 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/21 00:50:53 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_range(int r, t_element **b)
{
	int	i;
	int	k;
	int	ret;

	k = 1;
	i = (*b)->prev->val;
	while (k++ < r)
		*b = (*b)->next;
	if (i == (*b)->val)
	{
		ret = 0;
	}
	else
		ret = 1;
	while (k-- > 2)
		*b = (*b)->prev;
	return (ret);
}

int	check_sort(int r, t_element *temp)
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

void	find_maxmin(int r, t_element *a, int *max, int *min)
{
	int	val;

	val = a->val;
	*max = a->val;
	*min = a->val;
	while (r-- > 0)
	{
		if (a->val > *max)
			*max = a->val;
		if (a->val < *min)
			*min = a->val;
		a = a->next;
	}
}

void	sort_three(t_element **a)
{
	int	max;
	int	min;

	find_maxmin(3, *a, &max, &min);
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
}

void	btoa(int r, int flag, t_element **a, t_element **b)
{
	int	p;
	int	i;
	int	rb_cnt;
	int	pa_cnt;

//	printf("B st\n");
	flag = r_range(r, b);
	if (r == 1)
	{
		pab(a, b, "pa");
		return ;
	}
	else if (r == 2)
	{
		pab(a, b, "pa");
		pab(a, b, "pa");
		if ((*a)->val > (*a)->next->val)
			*a = sab(*a, "sa");
		return ;
	}
	rb_cnt = 0;
	pa_cnt = 0;
	p = pivot_sort(r, *b);
//	printf("r : %d p %d\n", r, p);
//	check_stack(*a, *b);
	while (r-- > 0)
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
	}
	i = rb_cnt;
	while (i-- > 0 && flag != 0)
		*b = rrab(*b, "rrb");
//	printf("B fn\n");
	atob(pa_cnt, flag, a, b);
	btoa(rb_cnt, flag, a, b);
}

int	checka(int r, t_element **a)
{
	if (check_sort(r, *a) == 1)
		return (1);
	else if (r == 2)
	{
		if ((*a)->val > (*a)->next->val)
			*a = sab(*a, "sa");
		return (1);
	}
	else if (r == 3)
	{
		if ((*a)->prev->val == (*a)->next->next->val)
				sort_three(a);
		return (1);
	}
	return (0);
}

void	atob(int r, int flag, t_element **a, t_element **b)
{
	int	p;
	int	i;
	int	ra_cnt;
	int	pb_cnt;

	flag = r_range(r, a);
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
		if ((*a)->prev->val == (*a)->next->next->val)
				return (sort_three(a));
	}
	ra_cnt = 0;
	pb_cnt = 0;
	p = pivot_sort(r, *a);
//	check_stack(*a, *b);
	while (r-- > 0)
	{
		if ((*a)->val > p)
		{
			*a = rab(*a, "ra");
			ra_cnt++;
		}
		else
		{
			pab(b, a, "pb");
			pb_cnt++;
		}
	}
	i = ra_cnt;
	while (i-- > 0 && flag != 0)
		*a = rrab(*a, "rra");
//	printf("A fin\n");
	atob(ra_cnt, flag, a, b);
	btoa(pb_cnt, flag, a, b);
}
