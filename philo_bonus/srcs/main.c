#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo		philo;
	t_thr_philo	*philos;
	int			i;
	int			status;

	i = -1;
	if (ft_init(argc, argv, &philo, &philos))
		return (1);
	while (++i < philo.num_philos)
	{
		philos[i].philo = &philo;
		philos[i].number = i + 1;
		philos[i].when_die = get_time(&philo) + philo.time_die;
		philos[i].ph_p = fork();
		if (philos[i].ph_p == -1)
			ft_close(philos, 9);
		if (philos[i].ph_p == 0)
			philo_process(&philos[i]);
	}
	if (philo.num_time_eat != -555)
		th_ate(philos);
	waitpid(-1, &status, 0);
	i = WEXITSTATUS(status);
	ft_close(philos, i);
	return (0);
}

void	th_ate(t_thr_philo *philos)
{
	if (pthread_create(&philos->philo->th_ate, NULL, check_ev, philos))
		ft_close(philos, 7);
	if (pthread_detach(philos->philo->th_ate))
		ft_close(philos, 7);
}

void	ft_close(t_thr_philo *philos, int err)
{
	int	i;

	i = -1;
	while (++i < philos->philo->num_philos)
		kill(philos[i].ph_p, 2);
	sem_close(philos->philo->forks);
	sem_close(philos->philo->forks);
	sem_unlink("forks");
	sem_unlink("mess");
	if (philos)
	{
		free(philos);
		philos = NULL;
	}
	exit(err);
}

void	*check_ev(void	*tmp_philos)
{
	t_thr_philo	*philos;
	int			i;

	i = 0;
	philos = tmp_philos;
	while (i < philos->philo->num_philos)
	{
		sem_wait(philos->philo->ev_ate);
		i++;
	}
	sem_close(philos->philo->ev_ate);
	sem_unlink("everyone_ate");
	ft_close(philos, 0);
	return ((void *)0);
}
