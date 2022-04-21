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
LINKEDLISTDIR = ./assets/linked_list/
LINKEDLIST = philoadd_back.c philoclear.c philodelone.c philolast.c philonew.c philosize.c
FULL_LINKEDLIST = $(addprefix $(LINKEDLISTDIR), $(LINKEDLIST))
SRC = ./src/main.c ./src/routine.c
NAME = philo

all: $(NAME)

$(NAME): $(SRC) $(FULL_LINKEDLIST)
	@make -C assets/libft/
	@$(CC) $(CFlags) $(LIBFT) $(FULL_LINKEDLIST) $(SRC) -o $@
	@echo $(BGreen)"Compiled successfuly ✅"$(Color_Off)

clean:
	@make clean -C assets/libft/

fclean: clean
	@make fclean -C assets/libft/
	@rm -f $(NAME);
	@echo $(BRed)"Project cleaned successfuly"$(Color_Off)