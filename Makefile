# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: obult <obult@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/04 16:49:28 by obult         #+#    #+#                  #
#    Updated: 2021/02/11 10:40:02 by oswin         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= printf.a

SRCS	= ./ft_printf.c ./utils.c ./cspdiuxX%/ft_alpha.c \
./cspdiuxX%/ft_pointer.c ./cspdiuxX%/ft_putnbr.c ./cspdiuxX%/va_utils.c

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
