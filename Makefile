NAME = push_swap

SRCS = push_swap.c stack.c error.c free_stack.c reverse.c rotate.c sort_big_functions.c sort_functions.c swap_push.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

${NAME}: libft
		${CC} ${CFLAGS} ${SRCS} -L ./libft -lft -o ${NAME}

all:	${NAME}

libft:
	make -C ./libft

clean:
		${RM} -f ${OBJS}
		make clean -C ./libft

fclean:	clean
		make fclean -C ./libft
		${RM} -f ${NAME}

re:		fclean ${MAKE} ${NAME}

.PHONY: all clean fclean re libft
