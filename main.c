/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:05:08 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/16 20:58:43 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	A_to_B(int r, int *flag, t_element **a, t_element **b);
void	B_to_A(int r, int *flag, t_element **a, t_element **b);
int		check_sort(int r, t_element *temp);
void check_stack(t_element *a, t_element *b);
void	sort_three(t_element **a);
int	get_pivot(int r, t_element *a);
void	find_maxmin(int r, t_element *a, int *max, int *min);
int find_pivot(int r, t_element *list);

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
	int max;
	int min;

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

void	sort_three_flag(t_element **a)
{
	int	max;
	int	min;
	
	find_maxmin(3, *a, &max, &min);
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

int five_pivot(int r, t_element *list)
{
	int min;
	int	max;
	int second;

	find_maxmin(5, list, &max, &min);
	min = max;
	second = max;
	while (r-- > 0)
	{
		if (list->val < min)
		{
			second = min;
			min = list->val;
		}
		else if (list->val < second && list->val != min)
			second = list->val;
		list = list->next;
	}
	return (second);
}

void swap(int *arr, int a, int b)
{
	int temp;

	temp = *(arr + a);
	*(arr + a) = *(arr + b);
	*(arr + b) = temp;
}

int partition(int *arr, int left, int right)
{
	int pivot;
	int low;
	int high;

	pivot = arr[left];
	low = left + 1;
	high = right;

	while (low <= high)
	{
		while (low <= right && pivot >= arr[low])
			low++;
		while (high >= (left + 1) && pivot <= arr[high])
			high--;
		if (low <= high)
			swap(arr, low, high);
	}
	swap(arr, left, high);
	return (high);	
}

void	q_sort(int *arr, int left, int right)
{
	int pivot;
	
	if (left <= right)
	{
		pivot = partition(arr, left, right);
		q_sort(arr, left, pivot - 1);
		q_sort(arr, pivot + 1, right);
	}
}

int		pivot_sort(int r, t_element *a)
{
	int	*arr;
	int i;
	int j;

	i = a->val;
	j = 0;
	arr = (int *)malloc(r * sizeof(int));
	while (1)
	{
		arr[j] = a->val;
		a = a->next;
		j++;
		if (a->next->val == i)
		{
			arr[j++] = a->val;
			break ;
		}
	}
	a = a->next;
	q_sort(arr, 0, r - 1);
	return (arr[(r / 2)]);
}

int		r_range(int r, t_element **b)
{
	int i;
	int	k;
	int ret;

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

void	B_to_A(int r, int *flag, t_element **a, t_element **b)
{
	int p;
	int i;
	int rb_cnt;
	int pa_cnt;
	int	cnt;

	if (r == 0)
		return ;
	else if (r == 1)
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
	cnt = 0;
	*flag = r_range(r, b);
	p = pivot_sort(r, *b);
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
	while (i-- > 0 && *flag != 0)
		*b = rrab(*b, "rrb");
	*flag = 1;
//	check_stack(*a, *b);
	A_to_B(pa_cnt, flag, a, b);
	B_to_A(rb_cnt, flag, a, b);
}

void	A_to_B(int r, int *flag, t_element **a, t_element **b)
{
	int p;
	int i;
	int ra_cnt;
	int pb_cnt;
	int cnt;

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
	//	return (sort_three_flag(a));
	}
	ra_cnt = 0;
	pb_cnt = 0;
	cnt = 0;
	p = pivot_sort(r, *a);
//	check_stack(*a, *b);
	i = r;
	while (i > 0)
	{
		if ((*a)->val > p)
		{
			*a = rab(*a, "ra");	
			ra_cnt++;
			cnt++;
		}
		else
		{
			pab(b, a, "pb");
			pb_cnt++;
			cnt = 0;
		}
		i--;
	}
	if (ra_cnt == 0)
			*b = sab(*b, "sb");
	i = ra_cnt;
	while (i-- > 0 && *flag != 0)
		*a = rrab(*a, "rra");
//	check_stack(*a, *b);
	A_to_B(ra_cnt, flag, a, b); //마지막자리 피봇을 ra 안해주기로 했기에 + 1
	B_to_A(pb_cnt, flag, a, b);
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
			break ;
	}
	printf("\n");
}

int	main(int nb, char **arg)
{
	t_element	*a;
	t_element	*b;
	t_program	prgm;
	int			flag;

	prgm_init(&prgm);
	a = NULL; //왜? 차이가 없어서 뺐다.
	b = NULL; //왜?? 일단 제거
	a = stack_init(nb, arg, &prgm);
	if (error_check(&prgm, nb, a) == 1)
		return (0);
	flag = 0;
	A_to_B(nb - 1, &flag, &a, &b);
//	check_stack(a, b);
	return (0);
}
