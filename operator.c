/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:05:16 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/21 00:50:24 by hyeonhki         ###   ########.fr       */
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
//	ab = del_top(ab);
	del_top2(&ab);
//	DeleteFrontNodeFromCListNode(&ab);
	temp2 = ab->val;
//	DeleteFrontNodeFromCListNode(&ab);
	del_top2(&ab);	
//	ab = del_top(ab);
//	push4(&ab, temp1);
//	push4(&ab, temp2);
	ab = push(ab, temp1);
	ab = push(ab, temp2);
	if (com)
		my_putstr(com);
	return (ab);
}

void	pab(t_element **ab, t_element **ba, char *com)
{
//	t_element *temp;

	if (*ba == NULL)
		return ;
//	check_stack(*ab, *ba);	
	*ab = push(*ab, (*ba)->val);
//	check_stack(*ab, *ba);
	//printf("A %d B %d\n",(*ab)->val, (*ba)->val);
//	system("leaks push_swap | grep \"total leaked\"");
//	DeleteFrontNodeFromCListNode(ba);
	del_top2(ba);
//	*ba = del_top(*ba);
//	system("leaks push_swap | grep \"total leaked\"");
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
