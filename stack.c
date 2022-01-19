/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:31:24 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/19 15:44:59 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*create_list(int val)
{
	t_element	*out;

	out = malloc(sizeof(t_element));
	if (out == NULL)
		return (NULL);
	out->val = val;
	out->next = out;
	out->prev = out;
	return (out);
}

t_element	*del_top(t_element *dest)
{
	t_element	*out;

	if (dest == NULL)
		return (NULL);
	if (dest == dest->next)
	{
		out = NULL;
		return (NULL);
	}
	out = malloc(sizeof(t_element));
	out = dest->next;
	out->prev = dest->prev;
	dest->prev->next = out;
	return (out);
}

t_element	*push(t_element *dest, t_element **from)
{
	t_element	*out;

	out = malloc(sizeof(t_element));
	if (out == NULL)
		return (NULL);
	if (dest == NULL)
	{
		free(out);
		return (create_list((*from)->val));
	}
	out->val = (*from)->val;
	out->next = dest;
	out->prev = dest->prev;
	dest->prev->next = out;
	dest->prev = out;
	return (out);
}

t_element	*pop(t_element *dest, t_element **to)
{
	t_element	*out;

	if (dest == NULL)
		return (NULL);
	if (dest == dest->next)
	{
		*to = push(*to, &dest);
		out = NULL;
		return (NULL);
	}
	out = malloc(sizeof(t_element));
	if (out == NULL)
		return (NULL);
	*to = push(*to, &dest);
	out = dest->next;
	out->prev = dest->prev;
	dest->prev->next = out;
	return (out);
}

t_element	*stack_init(int nb, char **arg, t_program *prgm)
{
	t_element	*a;
	t_element	*temp;

	temp = malloc(sizeof(t_element));
	a = NULL;
	while (nb > 1)
	{
		temp->val = my_getnbr(arg[nb - 1], prgm);
		a = push(a, &temp);
		nb--;
	}
	return (a);
}
