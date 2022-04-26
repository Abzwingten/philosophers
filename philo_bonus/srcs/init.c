#include "philo_bonus.h"

int	ft_init(int argc, char **argv, t_philo *philo, t_thr_philo **philos)
{
	if (parser(argc, argv, philo))
		return (3);
	*philos = (t_thr_philo *)malloc(sizeof(t_thr_philo) * philo->num_philos);
	if (!*philos)
		return (1);
	gettimeofday(&philo->tv, NULL);
	philo->start_t = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	sem_unlink("forks");
	sem_unlink("mess");
	if (philo->num_time_eat != -555)
	{
		sem_unlink("everyone_ate");
		philo->ev_ate = sem_open("everyone_ate", O_CREAT, S_IRWXG, 0);
		if (philo->ev_ate == SEM_FAILED)
			ft_close(*philos, 5);
	}
	philo->forks = sem_open("forks", O_CREAT, S_IRWXG, philo->num_philos);
	philo->mess = sem_open("mess", O_CREAT, S_IRWXG, 1);
	if (philo->forks == SEM_FAILED || philo->mess == SEM_FAILED)
		ft_close(*philos, 5);
	return (0);
}
