CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	fract-ol

# NAME_BONUS =

SRCS	=		exemple.c\
				exemple2

# SRCS_BONUS =

OBJS	=	$(SRCS:.c=.o)

# OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all	:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all bonus clean fclean re
