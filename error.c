/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:03:29 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/19 15:38:04 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(t_program *prgm, int nb, t_element *a)
{
	if (prgm->letter == 1)
		return (msg_error("Error\nLetter is included.\n"));
	if (prgm->range == 1)
		return (msg_error("Error\nInt range\n"));
	if (double_check(nb, a) == 1)
		return (msg_error("Error\nDouble!\n"));
	return (0);
}

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
