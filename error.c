/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:03:29 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/06 17:09:11 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	msg_error(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	return (1);
}

int	double_check(int nb, t_element *a)
{
	int	val;
	int	i;
	int	count;

	i = nb;
	while (i > 1)
	{
		val = a->val;
		count = nb;
		while (--count > 1)
		{
			if (val == a->next->val)
				return (1);
			a = a->next;
		}
		i--;
	}
	return (0);
}
