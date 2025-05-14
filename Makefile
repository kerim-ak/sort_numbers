NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = instructions/rotate.c instructions/rev_rotate.c instructions/swap.c instructions/push.c \
	utils/calculate_cost.c utils/check_error.c utils/ft_atol.c utils/put_stack_a.c \
	utils/sort_utils1.c utils/sort_utils2.c utils/sort_utils3.c utils/sort_utils4.c \
	utils/sort.c utils/split.c main.c

OBJS = $(SRCS:.c=.o)

FT_PRINTF = ft_printf/libftprintf.a

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean
	make -C ft_printf clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	make -C ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re