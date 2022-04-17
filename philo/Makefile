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


CC = gcc
CFlags = -pthread
LIBFT = -L ./assets/libft/ -lft

SRC = ./src/main.c
NAME = philo

all: $(NAME)

$(NAME): $(SRC)
	@make -C assets/libft/
	@$(CC) $(CFlags) $(LIBFT) $< -o $@
	@echo $(BGreen)"Compiled successfuly ✅"$(Color_Off)