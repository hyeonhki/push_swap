/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:05:08 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/19 15:42:41 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prgm_init(t_program *prgm)
{
	prgm->error = 0;
	prgm->letter = 0;
	prgm->nbrneg = 0;
	prgm->range = 0;
}

void	check_stack(t_element *a, t_element *b)
{
	t_element	*temp;

	temp = 0;
	printf("A : ");
	temp = a;
	while (1 && temp)
	{
		printf("%d ", temp->val);
		temp = temp->next;
		if ((a)->val == temp->val)
			break ;
	}
	printf("\nB : ");
	temp = b;
	while (1 && temp)
	{
		printf("%d ", temp->val);
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

	prgm_init(&prgm);
	a = stack_init(nb, arg, &prgm);
	if (error_check(&prgm, nb, a) == 1)
		return (0);
	atob(nb - 1, 0, &a, &b);
	return (0);
}
