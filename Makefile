# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 15:51:23 by rantario          #+#    #+#              #
#    Updated: 2022/04/09 15:51:24 by rantario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C philo

bonus:
	make -C philo_bonus

clean:
	make -C philo clean
	make -C philo_bonus clean

fclean:
	make -C philo fclean
	make -C philo_bonus fclean