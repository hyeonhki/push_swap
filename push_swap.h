/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:38:18 by hyeonhki          #+#    #+#             */
/*   Updated: 2021/12/04 22:04:22 by hyeonhki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_element
{
	int			val;
	struct		s_element	*next;
	struct		s_element	*prev;
}				t_element;

typedef struct	s_program
{
	int			letter;
	int			error;
	int			minus;
}				t_program;

#endif