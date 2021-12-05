/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:05:08 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/12/04 22:18:46 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int					my_getnbr(char *str, t_program *prgm)
{
	int		i;
	int		out;
	int		pow;

	pow = 1;
	out = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == '-')
			out = -out;
		else
		{
			out = out + ((str[i] - '0') * pow);
			pow = pow * 10;
		}
		i--;
	}
	return (out);
}


t_element	*stack_init(int nb, char **arg, t_program *prgm)
{
	t_element	*a;
	int			to_put;

	while (nb > 1)
	{
		to_put = my_getnbr(arg[nb - 1], prgm);
//		a = add_top(a, to_put);
		nb--;
	}
	return (a);
}

int			check_letter(char *str, t_program *prgm)
{
	if (*str == '-')
	{
			prgm->minus = -1;
			str++;
	}
	while (*str)
	{
		if (!(*str > '0' && *str < '9'))
			prgm->letter = 1;
		str++;
	}
	printf("%d\n",prgm->letter);
	if (prgm->letter == 1)
		return (1);
	return (0);
}

int		exit_error(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	return (0);
}

int			error_check(char **arg, int nb, t_program *prgm)
{
	while (nb > 1)
	{
		if (check_letter(arg[nb -1], prgm) == 1)
			return (1);
//		check_double;
//		check_range;
		nb --;
	}
	return (0);
}

void	prgm_init(t_program *prgm)
{
	prgm->error = 0;
	prgm->letter = 0;
	prgm->minus = 1;
}

int			main(int nb, char **arg)
{
	t_element	*a;
	t_element	*b;
	t_program	prgm;

	prgm_init(&prgm);
	if (error_check(arg, nb, &prgm) == 1)
		return (exit_error("Letter is included!"));
//	a = stack_init(arg, nb, &prgm);
	return (0);
}