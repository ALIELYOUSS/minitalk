# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 22:50:55 by alel-you          #+#    #+#              #
#    Updated: 2025/03/12 22:54:36 by alel-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = serve.c 

OBJC = $(FILES:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = server

all: $(NAME)

%.o: %.c ../minitalk.h
	@$(CC) $(FLAGS) -c $< -o $@
	
$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all