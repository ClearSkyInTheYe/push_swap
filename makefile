# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chfederi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 19:42:53 by chfederi          #+#    #+#              #
#    Updated: 2022/02/07 19:42:55 by chfederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap

SRCS = 35.c comands.c comands1.c ft_split.c main.c pushab.c sort.c  stackutils.c  stackutils1.c  utils.c  utils1.c                                                                                       sort.c stackutils.c stackutils1.c utils.c utils1.c

CFLAGS = -Wall -Wextra -Werror

CC = gcc

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all: $(OBJS) $(NAME)

35.o: 35.c $(HEADER)
	$(CC) $(CFLAGS) 35.c -c

comands.o: comands.c $(HEADER)
	$(CC) $(CFLAGS) comands.c -c

comands1.o: comands1.c $(HEADER)
	$(CC) $(CFLAGS) comands1.c -c

ft_split.o: ft_split.c  $(HEADER)
	$(CC) $(CFLAGS) ft_split.c -c

main.o: main.c $(HEADER)
	$(CC) $(CFLAGS) main.c -c

pushab.o: pushab.c $(HEADER)
	$(CC) $(CFLAGS) pushab.c -c

sort.o: sort.c $(HEADER)
	$(CC) $(CFLAGS) sort.c -c

stackutils.o:stackutils.c $(HEADER)
	$(CC) $(CFLAGS) stackutils.c -c

stackutils1.o:stackutils1.c $(HEADER)
	$(CC) $(CFLAGS) stackutils1.c -c

utils1.o:utils1.c $(HEADER)
	$(CC) $(CFLAGS) utils1.c -c

utils.o:utils.c $(HEADER)
	$(CC) $(CFLAGS) utils.c -c

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) *.o -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re