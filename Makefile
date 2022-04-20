# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 15:51:23 by rantario          #+#    #+#              #
#    Updated: 2022/04/11 11:21:50 by rantario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@mkdir -p bin
	@make -C philo
	@mv philo/philo bin/
	
bonus:
	@mkdir -p bin
	@make -C philo_bonus
	@mv philo_bonus/philo_bonus bin/
	
clean:
	make -C philo clean
	make -C philo_bonus clean

fclean:
	make -C philo fclean
	make -C philo_bonus fclean

re:
	make fclean all bonus