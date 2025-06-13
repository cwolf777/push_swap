CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT_DIR = ./libft
LIBFT_REPO = git@github.com:cwolf777/LIBFT.git
LIBFT_A = $(LIBFT_DIR)/libft.a
SOURCES = main.c ./init_list_utils/init_list_a.c ./init_list_utils/error_checks.c ./init_list_utils/free_list_end.c \
./init_list_utils/ft_atolo.c ./operations/swap.c ./operations/push.c ./operations/rotate.c ./operations/reverse_rotate.c \
./list_utils/in_order.c ./list_utils/count_list.c ./list_utils/find_min_max.c ./list_utils/find_cheapest.c ./list_utils/sort_three.c ./list_utils/start_with_min.c ./turk_algorithm/update_nodes_a.c \
./turk_algorithm/turk_algorithm.c ./turk_algorithm/get_nodes_to_top.c ./turk_algorithm/update_nodes_b.c ./turk_algorithm/check_top_of_list.c
OBJECTS = $(SOURCES:.c=.o)

all: clone_libft $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_A)  
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clone_libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "Cloning libft..."; \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -C $(LIBFT_DIR) clean; fi

fclean: clean
	rm -f $(NAME)
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -C $(LIBFT_DIR) fclean; fi

re: fclean all

.PHONY: all clean fclean re clone_libft
