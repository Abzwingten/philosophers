# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 15:51:23 by rantario          #+#    #+#              #
#    Updated: 2022/04/21 13:58:06 by rantario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@mkdir -p bin
	@make -C philo --no-print-directory
	@mv philo/philo bin/
	
bonus:
	@mkdir -p bin
	@make -C philo_bonus --no-print-directory
	@mv philo_bonus/philo_bonus bin/
	
clean:
	@make -C philo clean --no-print-directory
	@make -C philo_bonus clean --no-print-directory

fclean:
	@make -C philo fclean --no-print-directory
	@make -C philo_bonus fclean --no-print-directory
	@rm -rf bin

re:
	@make fclean all bonus --no-print-directory