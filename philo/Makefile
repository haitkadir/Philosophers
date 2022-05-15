# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 18:42:51 by haitkadi          #+#    #+#              #
#    Updated: 2022/05/15 18:42:54 by haitkadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White
# Reset
Color_Off='\033[0m'       # Text Reset

.PHONY: all clean fclean re
CC = gcc
CFlags = -Wall -Wextra -Werror -pthread
UTILS_SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isdigit.c ft_putstr_fd.c \
	ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c \
	ft_substr.c ft_lstadd_back.c ft_lstlast.c ft_lstnew.c ft_lstsize.c \
	ft_lstdelone.c ft_lstclear.c ft_atol.c ft_usleep.c ft_current_time.c

LINKEDLISTDIR = assets/linked_list/
UTILSDIR = 		assets/libft_funcs/
LINKEDLISTSRC = philoadd_back.c philolast.c philonew.c philosize.c

UTILS =		 $(addprefix $(UTILSDIR), $(UTILS_SRC))
LINKEDLIST = $(addprefix $(LINKEDLISTDIR), $(LINKEDLISTSRC))
ERRORS =	 $(addprefix src/errors/, errors_handling_util.c errors_handling.c)
PARSING =	 $(addprefix src/parsing/, parsing.c)
SRC =		 $(addprefix src/, routine.c routine_util.c recipe.c main.c)
NAME =		 philo

all: $(NAME)

$(NAME): $(UTILS) $(PARSING) $(ERRORS) $(LINKEDLIST) $(SRC)
	@$(CC) $(CFlags) $(UTILS) $(PARSING) $(ERRORS) $(LINKEDLIST) $(SRC) -o $@
	@echo $(BGreen)"Compiled successfuly ✅"$(Color_Off)

fclean:
	@rm -f $(NAME);
	@echo $(BRed)"Project cleaned successfuly"$(Color_Off)

re: fclean all
