CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SOURCES = push_swap.c printf_list.c ./init_list_utils/init_list_a.c ./init_list_utils/error_checks.c \
./init_list_utils/ft_atolo.c ./instructions/swap.c ./instructions/push.c ./instructions/rotate.c ./instructions/reverse_rotate.c \
./list_utils/in_order.c ./list_utils/count_list.c ./list_utils/find_max.c ./sort_algorithm/sort_three.c ./update_nodes/update_nodes.c \
turk_algorithm.c
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.
OBJECTS = $(SOURCES:.c=.o)

all:$(NAME)

$(NAME): $(OBJECTS) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJECTS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

