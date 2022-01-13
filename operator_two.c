/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:46:11 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/10 13:41:41 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_element **a, t_element **b)
{
	*a = rrab(*a, 0);
	*b = rrab(*b, 0);
}

void	ss(t_element **a, t_element **b)
{
	*a = sab(*a, 0);
	*b = sab(*b, 0);
	my_putstr("ss");
}

void	rr(t_element **a, t_element **b)
{
	*a = rab(*a, 0);
	*b = rab(*b, 0);
}
