# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 11:03:58 by jpyo              #+#    #+#              #
#    Updated: 2020/11/01 20:31:05 by hyungjki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= $(wildcard srcs/*.c)
HEADERS		= ./includes
TARGET		= rush-02
OBJS		= $(SRCS:.c=.o)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

$(OBJS) : $(SRCS) $(HEADERS)
	$(CC) -c $(CFLAGS) $(SRCS) -I $(HEADERS)
	mv *.o srcs/

.PHONY : all
all : $(TARGET)

.PHONY : clean
clean : 
	rm -f $(OBJS)

.PHONY : fclean
fclean : clean
	rm -f $(TARGET)

.PHONY : re
re : fclean all
