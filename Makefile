GNL= gnl/get_next_line_bonus.c 
NAME= push_swap.a
SRC= $(GNL) ./srcs/error.c ./srcs/parse.c ./srcs/utils.c ./srcs/functions_swap.c ./srcs/functions_push.c ./srcs/functions_rotate.c ./srcs/case_swap.c ./srcs/case_swap_utils.c ./srcs/push_swap_case.c ./srcs/push_swap_case_utils.c ./srcs/sort.c ./srcs/push_case_hundred.c ./srcs/ft_atoi_check.c
SRC+= 
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)

$(NAME):	$(OBJ)
	@make -sC ./libft/
	@make bonus -sC ./libft/
	@cp libft/libft.a .
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n\033[36m"****************\\nCompiled...\\n****************\\n"\033[0m\n"

run:
	@clear
	@echo "\n\033[36m"****************\\nStart...\\n****************\\n"\033[0m\n"
	@gcc -Wextra -Werror -Wall ./push_swap.c $(SRC) libft.a -o push_swap

bonus:
		@clear
		@echo "\n\033[36m"****************\\nStart...\\n****************\\n"\033[0m\n"
		@gcc -Wextra -Werror -Wall ./checker.c $(SRC) libft.a -o checker

all: $(NAME)

clean:
	@rm -f $(NAME) $(OBJ)
	@make -sC ./libft/ fclean
	@clear
	@echo "\n\033[36m"****************\\nDeleted files...\\n****************\\n"\033[0m\n"

fclean: clean
		@rm -rf libft.a
		@rm -rf push_swap
		@rm -rf checker
		@rm -rf *.t
	
re: clean all

.PHONY: all clean re run