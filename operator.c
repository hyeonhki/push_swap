/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:05:16 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/20 22:15:34 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*sab(t_element *ab, char *com)
{
	t_element	*out;
	int			temp1;
	int			temp2;

	out = NULL;
	if (ab == NULL || ab == ab->next)
		return (ab);
	temp1 = ab->val;
	ab = del_top(ab);
	temp2 = ab->val;
	ab = del_top(ab);
	ab = push(ab, temp1);
	ab = push(ab, temp2);
	if (com)
		my_putstr(com);
	return (ab);
}

void	pab(t_element **ab, t_element **ba, char *com)
{
	if (*ba == NULL)
		return ;
	*ab = push(*ab, (*ba)->val);
	*ba = del_top(*ba);
	my_putstr(com);
}

t_element	*rab(t_element *ab, char *com)
{
	t_element	*out;

	if (ab == NULL)
		return (NULL);
	out = ab->next;
	if (com)
		my_putstr(com);
	return (out);
}

t_element	*rrab(t_element *ab, char *com)
{
	t_element	*out;

	if (ab == NULL)
		return (NULL);
	out = ab->prev;
	if (com)
		my_putstr(com);
	return (out);
}
