# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 03:09:06 by alel-you          #+#    #+#              #
#    Updated: 2025/03/19 04:29:10 by alel-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ./server_bonus
	@make -C ./client_bonus
	@make -C ./server
	@make -C ./client

clean:
	@make clean -C ./server
	@make clean -C ./client

re:
	@make re -C ./server_bonus
	@make re -C ./client_bonus
	@make re -C ./server
	@make re -C ./client

fclean:
	@make fclean -C ./server_bonus
	@make fclean -C ./client_bonus
	@make fclean -C ./server
	@make fclean -C ./client

clean:
	@make clean -C ./server_bonus
	@make clean -C ./client_bonus
	@make clean -C ./server
	@make clean -C ./client
	
# bonus:
# 	@make -C ./server_bonus
# 	@make -C ./client_bonus

# re bonus:
# 	@make re -C ./server_bonus
# 	@make re -C ./client_bonus

# bonus fclean:
# 	@make fclean -C ./server_bonus
# 	@make fclean -C ./client_bonus
	
# bonus clean:
# 	@make clean -C ./server_bonus
# 	@make clean -C ./client_bonus