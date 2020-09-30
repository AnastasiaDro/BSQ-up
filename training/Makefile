# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerebus <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/22 13:33:39 by cerebus           #+#    #+#              #
#    Updated: 2020/09/22 18:27:52 by cerebus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	BSQ
FLAGS	=	-Wall -Wextra -Werror
HEADER	=	header.h
FHEADER	=	functions.h
SRC		=	main.c ft_putnbr.c min.c create_decis.c create_s_chars.c get_decis.c
CC		=	cc
OBJS	= 	${SRC:.c=.o}

.c.o:		
			${CC} -c ${FLAGS} ${SRC}

${NAME}: 	${OBJS}
			${CC} ${OBJS} -o ${NAME} -I ${HEADER} -I ${FHEADER}
		

all:		${NAME}
		
clean:
			rm -f ${OBJS}

fclean:		clean
			rm ${NAME}

.PHONY:		all clean fclean
