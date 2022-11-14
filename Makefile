# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josanton <josanton@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 01:47:06 by josanton          #+#    #+#              #
#    Updated: 2022/11/14 23:50:40 by josanton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	push_swap.c \
			ops/info.c \
			ops/normalize.c \
			ops/push_and_swap.c \
			ops/rotate_and_reverse.c \
			ops/free.c \
			algorithm/radix_sort.c

OBJS	=	${SRCS:%.c=${DIR_OBJ}%.o}

NAME	=	push_swap

#DIRECTORIES

LIBFT_DIR	=	libft/

DIR_OBJ = objs/

#GCC & FLAGS

CC	=	gcc

42FLAGS	=	-Wall -Wextra -Wextra

GCC	=	${CC} ${42FLAGS}

#CLEAN

RM	=	rm -f

#COLORS

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

# +*+*+**++*+*+*+*+*+*+**+ RULES ++*+**+**++*+*+*+*+*+*+*+*+*+

all:	${NAME} | submodule

${NAME}:	${OBJS} libft/libft.a ${DIR_OBJ}
	@${GCC} -o ${NAME} ${OBJS} -Llibft -lft
	@echo "${COLOUR_GREEN} >>> PUSH_SWAP OK <<< ${COLOUR_END}"

submodule:
	@git submodule update --init --recursive

${DIR_OBJ}%.o:%.c
	@mkdir -p ${dir $@}
	@${CC} ${42FLAGS} -c $< -o $@

libft/libft.a:
	@make -s -C ${LIBFT_DIR}

clean:
	@${RM} -r ${DIR_OBJ}
	@${MAKE} clean -C ${LIBFT_DIR}
	@echo "${COLOUR_YELLOW} >>> OBJS CLEANED <<< ${COLOUR_END}"

fclean:		clean
	@${MAKE} fclean -C ${LIBFT_DIR}
	@${RM} ${NAME}
	@echo "${COLOUR_YELLOW} >>> ALL CLEANED <<< ${COLOUR_END}"

re:	fclean all

.PHONY:	all clean fclean re libft submodule
