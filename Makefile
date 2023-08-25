CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRCS = ./error.c ./linked_list.c ./push_swap.c ./operations.c ./simplify_list.c ./small_sort.c ./sort_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
