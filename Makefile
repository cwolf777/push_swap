CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SOURCES = push_swap.c printf_list.c init_list_a.c error_checks.c ft_atolo.c swap.c push.c rotate.c reverse_rotate.c
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

