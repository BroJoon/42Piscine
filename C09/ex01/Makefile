CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR 		= ar
ARFLAGS = rcs
SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
TARGET	= libft.a
RM		= rm -f

.PHONY: all clean fclean re .c.o

all: ${TARGET}

${TARGET}: ${OBJS}
	${AR} ${ARFLAGS} $@ $<

clean:
	${RM} {OBJS}

fclean: cleano
	${RM} ${TARGET}

re: fclean all

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}
