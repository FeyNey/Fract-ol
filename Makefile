CC	=	cc

CFLAGS	=	-g -Wall -Wextra -Werror

NAME	=	fract-ol

# NAME_BONUS =

SRCS	=		utils.c\
				main.c

# SRCS_BONUS =

OBJS	=	$(SRCS:.c=.o)

# OBJS_BONUS = $(SRCS_BONUS:.c=.o)

MLX_PATH =
MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext


all	:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
		@make -C minilibx-linux/
		$(CC) $(OBJS) $(MLX) -o $(NAME)
# (CFLAGS)
clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all bonus clean fclean re
