#include "philo.h"

void	*philo_loop(void *phil)
{
	t_thr_philo	*tmp_phil;

	tmp_phil = phil;
	if (tmp_phil->number % 2)
		ft_usleep(tmp_phil->philo->time_eat, tmp_phil);
	while (1)
	{
		if (!take_forks(tmp_phil))
			return (NULL);
		if (tmp_phil->philo->num_time_eat != -555)
		{
			pthread_mutex_lock(&tmp_phil->philo->mut_eat_c);
			tmp_phil->eat_num++;
			pthread_mutex_unlock(&tmp_phil->philo->mut_eat_c);
		}
		thr_eating(tmp_phil);
		if (tmp_phil->philo->exit)
		{
			pthread_mutex_unlock(&tmp_phil->philo->mt_exit);
			return (NULL);
		}
		pthread_mutex_unlock(&tmp_phil->philo->mt_exit);
		print_m(phil, "is thinking", 1);
	}
	return (NULL);
}

void	thr_eating(t_thr_philo *tmp_phil)
{
	pthread_mutex_lock(&tmp_phil->mut_death);
	tmp_phil->when_die += tmp_phil->philo->time_die;
	pthread_mutex_unlock(&tmp_phil->mut_death);
	print_m(tmp_phil, "is eating", 1);
	ft_usleep(tmp_phil->philo->time_eat, tmp_phil);
	philo_sleep(tmp_phil);
	pthread_mutex_lock(&tmp_phil->philo->mt_exit);
}

void	*take_forks(t_thr_philo *tmp_phil)
{
	if (tmp_phil->number == 1)
	{
		try_take_fork(&tmp_phil->mut_frk, tmp_phil);
		if (tmp_phil->philo->num_philos == 1)
		{
			pthread_mutex_unlock(&tmp_phil->mut_frk);
			return (NULL);
		}
		try_take_fork(&tmp_phil[tmp_phil->philo->num_philos - 1].mut_frk, \
					tmp_phil);
	}
	else
	{
		try_take_fork(&(tmp_phil - 1)->mut_frk, tmp_phil);
		try_take_fork(&tmp_phil->mut_frk, tmp_phil);
	}
	pthread_mutex_lock(&tmp_phil->philo->mt_exit);
	if (tmp_phil->philo->exit)
	{
		pthread_mutex_unlock(&tmp_phil->philo->mt_exit);
		philo_sleep(tmp_phil);
		return (NULL);
	}
	pthread_mutex_unlock(&tmp_phil->philo->mt_exit);
	return (tmp_phil);
}

void	philo_sleep(t_thr_philo *phil)
{
	if (phil->number == 1)
	{
		pthread_mutex_unlock(&phil[phil->philo->num_philos - 1].mut_frk);
		pthread_mutex_unlock(&phil->mut_frk);
	}
	else
	{
		pthread_mutex_unlock(&phil->mut_frk);
		pthread_mutex_unlock(&(phil - 1)->mut_frk);
	}
	pthread_mutex_lock(&phil->philo->mt_exit);
	if (phil->philo->exit)
	{
		pthread_mutex_unlock(&phil->philo->mt_exit);
		return ;
	}
	pthread_mutex_unlock(&phil->philo->mt_exit);
	print_m(phil, "is sleeping", 1);
	ft_usleep(phil->philo->time_sleep, phil);
}

void	try_take_fork(pthread_mutex_t *mut_frk, t_thr_philo *philos)
{
	pthread_mutex_lock(mut_frk);
	pthread_mutex_lock(&philos->philo->mt_exit);
	if (philos->philo->exit)
	{
		pthread_mutex_unlock(&philos->philo->mt_exit);
		return ;
	}
	pthread_mutex_unlock(&philos->philo->mt_exit);
	print_m(philos, "has taken a fork", 1);
}
