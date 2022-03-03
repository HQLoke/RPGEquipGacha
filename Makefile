NAME = rpg

CC = gcc
CFLAGS = #-Wall -Wextra -Werror
RM = rm -f

MAIN = main.c
SRCS = new_equip.c utils.c
OBJS = ${SRCS:.c=.o}

INCLUDE = -Iinclude

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${INCLUDE} -o ${NAME} ${MAIN} ${OBJS}

%.o: %.c
	${CC} ${INCLUDE} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re