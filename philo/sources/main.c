#include "philo.h"

int	create_threads(t_thr_philo *philos, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_philos)
	{
		philos[i].philo = philo;
		philos[i].number = i + 1;
		if (philo->num_time_eat != -555)
			philos[i].eat_num = 0;
		philos[i].when_die = get_time(philo) + philo->time_die;
		if (pthread_create(&philos[i].philo_loop, NULL, philo_loop, &philos[i]))
		{
			free(philos);
			return (1);
		}
		i++;
	}
	if (pthread_create(&philo->th_die, NULL, death_1, philos))
	{
		free(philos);
		return (1);
	}
	return (0);
}

int	philo_destroy(t_thr_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->philo->num_philos)
	{
		if (pthread_join(philos[i].philo_loop, NULL))
		{
			free(philos);
			return (5);
		}
		pthread_mutex_destroy(&philos[i].mut_frk);
		pthread_mutex_destroy(&philos[i].mut_death);
		i++;
	}
	i = 0;
	if (pthread_join(philos->philo->th_die, NULL))
		i = 5;
	pthread_mutex_destroy(&philos->philo->mt_mess);
	pthread_mutex_destroy(&philos->philo->mut_eat_c);
	pthread_mutex_destroy(&philos->philo->mt_exit);
	free(philos);
	return (i);
}

t_thr_philo	*philo_init(int argc, char **argv, t_philo *philo)
{
	t_thr_philo	*philos;
	int			i;

	i = -1;
	if (parser(argc, argv, philo))
		return (NULL);
	if (pthread_mutex_init(&philo->mt_mess, NULL) \
	|| pthread_mutex_init(&philo->mut_eat_c, NULL) \
	|| pthread_mutex_init(&philo->mt_exit, NULL))
		return (NULL);
	philos = (t_thr_philo *)malloc(sizeof(t_thr_philo) * philo->num_philos);
	if (!philos)
		return (NULL);
	gettimeofday(&philo->tv, NULL);
	philo->start_t = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	while (++i < philo->num_philos)
	{
		if (pthread_mutex_init(&philos[i].mut_frk, NULL) \
		|| pthread_mutex_init(&philos[i].mut_death, NULL))
		{
			free(philos);
			return (NULL);
		}
	}
	return (philos);
}

void	print_m(t_thr_philo *philos, char *str, int flag)
{
	pthread_mutex_lock(&philos->philo->mt_mess);
	pthread_mutex_lock(&philos->philo->mt_exit);
	if (philos->philo->exit && flag)
	{
		pthread_mutex_unlock(&philos->philo->mt_exit);
		pthread_mutex_unlock(&philos->philo->mt_mess);
		return ;
	}
	pthread_mutex_unlock(&philos->philo->mt_exit);
	printf("%llu %d %s\n", get_time(philos->philo), philos->number, str);
	pthread_mutex_unlock(&philos->philo->mt_mess);
}

int	main(int argc, char **argv)
{
	t_philo		philo;
	t_thr_philo	*philos;

	philos = philo_init(argc, argv, &philo);
	if (!philos)
		return (3);
	if (create_threads(philos, &philo))
		return (3);
	return (philo_destroy(philos));
}
