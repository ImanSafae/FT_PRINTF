FILES = ft_printf_utils.c ft_printf_utils2.c ft_printf.c

OBJS = ${FILES:.c=.o}


NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

%.o:	%.c
	gcc -c ${FLAGS} -o $@ $<  

all:	${NAME}

${NAME}:${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
