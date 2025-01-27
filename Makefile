CC	=	cc

CFLAGS	= -Wall -Wextra -Werror -O3

NAME	=	fractol

# NAME_BONUS =

SRCS	=		src/main.c\
				src/init.c\
				src/render.c\
				src/math.c\
				src/hook.c\
				src/Mandelbrot.c\
				src/Julia.c\
				src/Newton.c

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
		$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)
clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all bonus clean fclean re
