# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 09:54:35 by barbizu-          #+#    #+#              #
#    Updated: 2022/09/22 11:23:16 by barbizu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	   ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
	   ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	   ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	   	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

PRINTF = ft_printf.c ft_printf_utils.c ft_unsigned.c ft_ptr.c

OBJS = ${SRCS:.c=.o}

OBJS_B = ${BONUS:.c=.o}

OBJS_P = ${PRINTF:.c=.o}

NAME = libft.a

INCLUDES = includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rc ${NAME} ${OBJS}

bonus:	${OBJS} ${OBJS_B}
	ar -rc ${NAME} ${OBJS} ${OBJS_B}

printf:	${OBJS} ${OBJS_B} ${OBJS_P}
	ar -rc ${NAME} ${OBJS} ${OBJS_B} ${OBJS_P}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJS_B} ${OBJS_P}

fclean:
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus printf
