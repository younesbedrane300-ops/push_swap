NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude

SRC = \
	src/main.c \
	src/parse.c \
	src/utils.c \
	src/stack.c \
	src/ops_swap_push.c \
	src/ops_rotate.c \
	src/sort_simple.c \
	src/sort_medium.c \
	src/sort_complex.c \
	src/sort_adaptive.c \
	src/bench.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = \
	src/checker_bonus.c \
	src/checker_parse_bonus.c \
	src/parse.c \
	src/utils.c \
	src/stack.c \
	src/ops_swap_push.c \
	src/ops_rotate.c \
	src/bench.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(CHECKER)

%.o: %.c include/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re
