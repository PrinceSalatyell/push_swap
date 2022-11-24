# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josanton <josanton@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 01:47:06 by josanton          #+#    #+#              #
#    Updated: 2022/11/24 01:07:43 by josanton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	push_swap.c \
			ops/info.c \
			ops/normalize.c \
			ops/push_and_swap.c \
			ops/rotate_and_reverse.c \
			ops/free.c \
			algorithm/radix_sort.c \
			algorithm/algo_for_three.c\
			algorithm/algo_for_five.c

OBJS	=	${SRCS:%.c=${DIR_OBJ}%.o}

NAME	=	push_swap

#DIRECTORIES

LIBFT_DIR	=	libft/

DIR_OBJ = objs/

#GCC & FLAGS

CC	=	gcc

42FLAGS	=	-Wall -Wextra -Wextra -g -fsanitize=address

GCC	=	${CC} ${42FLAGS}

#CLEAN

RM	=	rm -f

#COLORS

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

# +*+*+**++*+*+*+*+*+*+**+ RULES ++*+**+**++*+*+*+*+*+*+*+*+*+

all:	${NAME}

${NAME}:	${OBJS} libft/libft.a
	@${GCC} -o ${NAME} ${OBJS} -Llibft -lft
	@echo "${COLOUR_GREEN} >>> PUSH_SWAP OK <<< ${COLOUR_END}"

${DIR_OBJ}%.o:%.c
	@git submodule update --init --recursive
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
