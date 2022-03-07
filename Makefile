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