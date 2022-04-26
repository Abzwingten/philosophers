#include "philo.h"

void	*death_1(void *philos)
{
	t_thr_philo	*tmp_philos;
	t_ull	ntime;
	int			i;
	int			neat;

	i = 0;
	neat = 0;
	tmp_philos = philos;
	while (1)
	{
		ntime = get_time(tmp_philos[i].philo);
		while (i < tmp_philos->philo->num_philos)
		{
			if (death_2(tmp_philos, ntime, &i, &neat))
				return (NULL);
		}
		if (i == neat)
			return (death_3(tmp_philos));
		usleep(100);
		i = 0;
		neat = 0;
	}
}

int	death_2(t_thr_philo *tmp_philos, t_ull ntime, int *i, int *neat)
{
	pthread_mutex_lock(&tmp_philos[*i].mut_death);
	if (tmp_philos[*i].when_die <= ntime)
	{
		pthread_mutex_unlock(&tmp_philos[*i].mut_death);
		pthread_mutex_lock(&tmp_philos->philo->mt_exit);
		tmp_philos->philo->exit = 1;
		pthread_mutex_unlock(&tmp_philos->philo->mt_exit);
		print_m(&tmp_philos[*i], "died", 0);
		return (1);
	}
	pthread_mutex_unlock(&tmp_philos[*i].mut_death);
	pthread_mutex_lock(&tmp_philos->philo->mut_eat_c);
	if (tmp_philos[*i].philo->num_time_eat != -555 \
		&& tmp_philos[*i].eat_num >= tmp_philos[*i].philo->num_time_eat)
		(*neat)++;
	pthread_mutex_unlock(&tmp_philos->philo->mut_eat_c);
	(*i)++;
	return (0);
}

void	*death_3(t_thr_philo *tmp_philos)
{
	pthread_mutex_lock(&tmp_philos->philo->mt_exit);
	tmp_philos->philo->exit = 1;
	pthread_mutex_unlock(&tmp_philos->philo->mt_exit);
	return (NULL);
}