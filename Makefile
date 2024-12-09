CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SOURCES = push_swap.c ./init_list_utils/init_list_a.c ./init_list_utils/error_checks.c \
./init_list_utils/ft_atolo.c ./instructions/swap.c ./instructions/push.c ./instructions/rotate.c ./instructions/reverse_rotate.c \
./list_utils/in_order.c ./list_utils/count_list.c ./list_utils/find_min_max.c ./list_utils/find_cheapest.c ./list_utils/sort_three.c ./list_utils/start_with_min.c ./turk_algorithm/update_nodes_a.c \
./turk_algorithm/turk_algorithm.c ./turk_algorithm/get_nodes_to_top.c ./turk_algorithm/update_nodes_b.c ./turk_algorithm/check_top_of_list.c
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

