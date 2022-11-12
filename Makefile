NAME	= minishell

SRCS	= $(shell find "." -name "*.c")
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror 
READFL  = -lreadline
RM		= rm -f

%.o : %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${READFL} ${OBJS} -o ${NAME}

clean : 
	${RM} ${OBJS}
	
fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re