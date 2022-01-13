# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonhki <hyeonhki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 10:29:00 by hyeonhki          #+#    #+#              #
#    Updated: 2022/01/06 16:49:09 by hyeonhki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
SRCS	= main.c utils.c error.c stack.c operator.c operator_two.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I -fsanitize=address

all	: 	$(NAME)

$(NAME)	: 	$(OBJS)
		cc $(OBJS) $(CFLAGS) -o $(NAME)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY :	all clean fclean re