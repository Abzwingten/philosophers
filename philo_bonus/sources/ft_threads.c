#include "philo_bonus.h"

void	threads_start(t_table *table)
{
	size_t	i;

	sem_unlink("forks");
	sem_unlink("printing");
	sem_unlink("diying");
	table->is_printing = sem_open("printing", O_CREAT, 0666, 1);
	table->is_dying = sem_open("diying", O_CREAT, 0666, 1);
	table->forks = sem_open("forks", O_CREAT, 0666, table->count);
	i = -1;
	while (++i < table->count)
		philo_init(table->philos + i, table, i);
	i = -1;
	while (++i < table->count)
	{
		pthread_create(&table->philos[i].thread, NULL, \
						philo_routine, table->philos + i);
	}
	philo_check_death(table);
}

void	threads_wait(t_table *table)
{
	ft_usleep(100);
	sem_unlink("forks");
	sem_unlink("diying");
	sem_unlink("printing");
	free(table->philos);
	free(table);
}
