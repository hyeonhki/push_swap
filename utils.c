/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:26:09 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/16 16:57:25 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_putstr(char *str)
{
	if (str == 0)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

unsigned int	my_strlen(const char *str, t_program *prgm)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			if (str[i] != '-')
				prgm->letter = 1;
		i++;
	}
	return (i);
}

int	check_range(char m, int in, int ret, t_program *prgm)
{
	if (in > 2)
	{
		prgm->range = 1;
		return (0);
	}
	if (in == 2)
	{
		if (m == '-')
		{
			if (ret > 147483648)
			{
				prgm->range = 1;
				return (0);
			}
		}
		else if (ret > 147483647)
		{
			prgm->range = 1;
			return (0);
		}	
	}
	return (0);
}

int	my_getnbr(char *str, t_program *prgm)
{
	int		i;
	int		out;
	int		pow;

	pow = 1;
	out = 0;
	i = my_strlen(str, prgm) - 1;
	while (i >= 0)
	{
		if (str[i] == '-')
		{
			prgm->nbrneg += 1;
			out = -out;
		}
		else
		{
			if (pow > 100000000)
				check_range(str[0], str[i] - '0', out, prgm);
			out = out + ((str[i] - '0') * pow);
			pow = pow * 10;
		}
		i--;
	}
	return (out);
}
