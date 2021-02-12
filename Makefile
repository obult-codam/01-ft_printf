# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: obult <obult@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/04 16:49:28 by obult         #+#    #+#                  #
#    Updated: 2021/02/12 13:54:39 by oswin         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ./ft_printf.c ./ft_utils.c ./ft_alpha.c \
./ft_pointer.c ./ft_putnbr.c ./ft_va_utils.c ./ft_decimal.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -f

HEADER	= -I

CFLAGS	= -Wall -Werror -Wextra

LIB		= ar -rsc

all:		${NAME}

.c.o:
				${CC} -c ${CFLAGS} $< -o ${<:.c=.o}
clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

${NAME}:	${OBJS}
				${LIB} $@ $^

.PHONY: all clean fclean re
