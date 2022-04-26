#include "philosophers_bonus.h"

void	ph_proc(t_th_phil *phils)
{
	int	ph_ate;

	ph_ate = 0;
	if (pthread_create(&phils->th_die, NULL, when_die, phils))
		exit(5);
	if (pthread_detach(phils->th_die))
		exit(5);
	if (pthread_mutex_init(&phils->mt_die, NULL))
		exit(5);
	if (phils->number % 2)
		ft_usleep(phils->philo->time_eat, phils);
	while (1)
	{
		phil_is_eating(phils, &ph_ate);
		if (sem_post(phils->philo->forks) || sem_post(phils->philo->forks))
			exit(5);
		print_m(phils, "is sleeping", 1);
		ft_usleep(phils->philo->time_sleep, phils);
		print_m(phils, "is thinking", 1);
	}
	exit(0);
}

void	phil_is_eating(t_th_phil *phils, int *ph_ate)
{
	if (sem_wait(phils->philo->forks))
		exit(5);
	print_m(phils, "has taken a fork", 1);
	if (sem_wait(phils->philo->forks))
		exit(5);
	print_m(phils, "has taken a fork", 1);
	pthread_mutex_lock(&phils->mt_die);
	phils->when_die += phils->philo->time_die;
	pthread_mutex_unlock(&phils->mt_die);
	print_m(phils, "is eating", 1);
	if (phils->philo->num_time_eat != -555 \
		&& *ph_ate < phils->philo->num_time_eat)
		(*ph_ate)++;
	if (phils->philo->num_time_eat != -555 \
		&& *ph_ate == phils->philo->num_time_eat)
	{
		if (sem_post(phils->philo->ev_ate))
			exit(5);
		(*ph_ate)++;
	}
	ft_usleep(phils->philo->time_eat, phils);
}

void	ft_usleep(t_ull ms, t_th_phil *phils)
{
	t_ull	ms_end;
	t_ull	ms_now;

	gettimeofday(&phils->philo->tv, NULL);
	ms_now = (phils->philo->tv.tv_sec * 1000) + \
	(phils->philo->tv.tv_usec / 1000);
	ms_end = ms_now + ms;
	while (ms_now < ms_end)
	{
		gettimeofday(&phils->philo->tv, NULL);
		ms_now = (phils->philo->tv.tv_sec * 1000) + \
		(phils->philo->tv.tv_usec / 1000);
		usleep(100);
	}
}

void	*when_die(void *tmp_phil)
{
	t_th_phil	*phil;

	phil = tmp_phil;
	while (1)
	{
		pthread_mutex_lock(&phil->mt_die);
		if (phil->when_die <= get_time(phil->philo))
		{
			print_m(phil, "died", 0);
			exit(0);
			break ;
		}
		pthread_mutex_unlock(&phil->mt_die);
		usleep(100);
	}
	return (NULL);
}

void	print_m(t_th_phil *phils, char *str, int flag)
{
	if (sem_wait(phils->philo->mess))
		exit(7);
	printf("%llu %d %s\n", get_time(phils->philo), phils->number, str);
	if (flag)
	{
		if (sem_post(phils->philo->mess))
			exit(7);
	}
}
