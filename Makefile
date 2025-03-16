# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 03:09:06 by alel-you          #+#    #+#              #
#    Updated: 2025/03/15 03:12:30 by alel-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ./server
	@make -C ./client

clean:
	@make clean -C ./server
	@make clean -C ./client

re:
	@make re -C ./server
	@make re -C ./client

fclean: clean re