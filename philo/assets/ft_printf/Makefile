# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 16:04:21 by haitkadi          #+#    #+#              #
#    Updated: 2021/12/02 16:04:23 by haitkadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_atoi.c ft_bzero.c ft_check_error.c ft_isdigit.c ft_manage_flags.c\
	ft_numlen.c ft_print_data.c ft_print_flags.c ft_printf.c ft_process_c.c\
	ft_process_d.c ft_process_p.c ft_process_s.c ft_process_u.c\
	ft_process_x.c ft_strchr.c ft_strlen.c ft_tolower.c

SRC_OBJECTS = $(SRC:%.c=%.o)

$(NAME): $(SRC_OBJECTS)
	@ar rcs $(NAME) $(SRC_OBJECTS)
	@rm -f $(SRC_OBJECTS)

all: $(NAME)

%.o:%.c ft_printf.h
	@$(CC) $(CFLAGS) -o $@ -c $<

bonus: all

clean:
	@rm -f $(SRC_OBJECTS)

fclean: clean
	@rm -f $(NAME) a.out

re: fclean all

compile: all
	@$(CC) $(CFLAGS) main.c -L. -lftprintf
	@./a.out

.PHONY: all bonus clean fclean re compile