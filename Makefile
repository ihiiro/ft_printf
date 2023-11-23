# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 10:12:23 by yel-yaqi          #+#    #+#              #
#    Updated: 2023/11/23 17:58:57 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c helpers.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $< -c

$(NAME): $(OBJS)
	ar -rc $(NAME) $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re