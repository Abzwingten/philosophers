#include "philo.h"

void	threads_start(t_table *table)
{
	size_t	i;

	pthread_mutex_init(&table->is_printing, NULL);
	pthread_mutex_init(&table->is_dying, NULL);
	i = -1;
	while (++i < table->count)
		philo_init(table->philos + i, table, i);
	i = -1;
	while (++i < table->count)
		philo_init_forks(table->philos + i, table, i);
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
	size_t	i;

	ft_usleep(100);
	i = -1;
	while (++i < table->count)
		pthread_mutex_destroy(table->forks + i);
	pthread_mutex_destroy(&table->is_printing);
	free(table->philos);
	free(table->forks);
	free(table);
}
