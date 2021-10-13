NAME = philo
OBJ_DIR = .objs

SRC =	main.c

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

CC = clang
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "\033[1;32m[OK]\033[0m    \033[1;33mCompiling\033[0m $(<F)"

clean:
		@$(RM) $(OBJ_DIR)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PONY: all clean fclean re
