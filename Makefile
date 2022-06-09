# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alyasar <alyasar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 16:11:09 by alyasar           #+#    #+#              #
#    Updated: 2022/06/02 16:11:16 by alyasar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
CC = gcc
FLAGS = -Wall -Werror -Wextra

$(NAME): $(SERVER) $(CLIENT)

all: $(NAME)

$(SERVER): server.o utils.o utils2.o
	$(CC) server.o utils.o utils2.o -o $@

$(CLIENT): client.o utils.o utils2.o
	$(CC) client.o utils.o utils2.o -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $?

clean:
	rm -f *.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all