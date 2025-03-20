# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 22:50:55 by alel-you          #+#    #+#              #
#    Updated: 2025/03/20 03:44:08 by alel-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = client.c ../utils/help_utils.c ../utils/ft_atoi.c

OBJC = $(FILES:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = client

all: $(NAME)

%.o: %.c ../minitalk.h
	@$(CC) $(OBJ) $(FLAGS) -c $< -o $@
	
$(NAME): $(OBJC)
	@$(CC) $(OBJC) $(FLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJC)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
