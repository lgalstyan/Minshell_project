NAME	= minishell
DIRS	= run parse
SRCS	= $(shell find ${DIRS} -name "*.c")
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I ./headers #-fsanitize=address -g
LINKER	= -L./readline_larisa/lib -lreadline
INCLUDE	= -I ./headers -I./readline_larisa/include
READFL  = -lreadline
RD		= ${shell find ${HOME} -name readline_larisa 2>/dev/null}
RM		= rm -f

%.o : %.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${READFL} ${OBJS} ${LINKER} -o ${NAME}

clean : 
	${RM} ${OBJS}
	
fclean: clean
	${RM} ${NAME}

install:
	cd readline-master && make clean && ./configure --prefix=${RD} && make && make install

re: fclean all

.PHONY: all clean fclean re