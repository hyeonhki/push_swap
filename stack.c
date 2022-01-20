/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:31:24 by hyeonhki          #+#    #+#             */
/*   Updated: 2022/01/21 00:32:24 by hyeonhki         ###   ########.fr       */
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

void		DeleteFrontNodeFromCListNode(t_element **head)
{
	t_element *removed;
	t_element *tail;
	
	removed = *head;
	if (*head == NULL)
		return ;
	if (*head == (*head)->next)
		*head = NULL;
	else 
	{
		tail = *head;
	//	printf("tail %d tail %d tail %d tail %d\n",tail->val,tail->next->val,tail->next->next->val,tail->next->next->next->val);
		while (tail->next != *head)
		{
			tail = tail->next;
		}
		if (tail == *head)
			*head = NULL;
		else
		{
			*head = (*head)->next;
			tail->next = *head;
		}
	//	free(removed);
	}
	
}

void		del_top2(t_element **head)
{
	t_element	*removed;
	t_element	*tail;

	if (*head == NULL)
		return ;
	removed = *head;
	tail = (*head)->prev;
	if (*head == (*head)->next)
		*head = NULL;
	else
	{
		*head = (*head)->next;
		tail->next = *head;
		(*head)->prev = tail;
	}
	//free(removed);
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
//	oddut = malloc(sizeof(t_element));
	out = dest->next;
	out->prev = dest->prev;
	out->prev->next = out;
	dest->prev = NULL;
	dest->next = NULL;
//	free(dest);
	dest = NULL;
	return (out);
}

void		push3(t_element **head, int val)
{
	t_element	*inserted;
	t_element	*tail;

	inserted = malloc(sizeof(t_element));
	inserted->val = val;
	if (*head == NULL)
	{
		*head = inserted;
		inserted->next = *head;
	}
	else
	{
		tail = *head;
		while (tail->next != *head)
			tail = tail->next;
		inserted->next = *head;
		*head = inserted;
		tail->next = *head;
	}
}

t_element	*new_node(int nb)
{
	t_element	*node;

	if (!(node = (t_element *) malloc(sizeof(t_element))))
		return (0);
	node->val = nb;
	node->next = 0;
	return (node);
}

int		push2(t_element **stack, int elem)
{
	t_element *new;

	if (!stack)
		return (0);
	if (!*stack)
	{
		if (!(*stack = new_node(elem)))
			return (0);
		return (1);
	}
	if (!(new = new_node(elem)))
		return (0);
	new->next = *stack;
	*stack = new;
	return (1);
}

void	push4(t_element **dest, int val)
{
	t_element	*out;

	out = malloc(sizeof(t_element));
	if (out == NULL)
			return ;
	if (dest == NULL)
		*dest = create_list(val);
	else
	{
		out->val = val;
		out->next = *dest;
		out->prev = (*dest)->prev;
		(*dest)->prev->next = out;
		(*dest)->prev = out;
	}
}

// b, a
t_element	*push(t_element *dest, int val)
{
	t_element	*out;

	out = malloc(sizeof(t_element));
	if (out == NULL)
		return (NULL);
	if (dest == NULL)
	{
		free(out);
		return (create_list(val));
	}
	out->val = val;
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
		*to = push(*to, dest->val);
		out = NULL;
		return (NULL);
	}
	*to = push(*to, dest->val);
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
		a = push(a, temp->val);
	//	push4(&a, temp->val);
		nb--;
	}
	free(temp);
	return (a);
}
