#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_philo		philo;
	t_th_phil	*phils;
	int			i;
	int			status;

	i = -1;
	if (ft_init(argc, argv, &philo, &phils))
		return (1);
	while (++i < philo.num_phils)
	{
		phils[i].philo = &philo;
		phils[i].number = i + 1;
		phils[i].when_die = get_time(&philo) + philo.time_die;
		phils[i].ph_p = fork();
		if (phils[i].ph_p == -1)
			ft_close(phils, 9);
		if (phils[i].ph_p == 0)
			ph_proc(&phils[i]);
	}
	if (philo.num_time_eat != -555)
		th_ate(phils);
	waitpid(-1, &status, 0);
	i = WEXITSTATUS(status);
	ft_close(phils, i);
	return (0);
}

void	th_ate(t_th_phil *phils)
{
	if (pthread_create(&phils->philo->th_ate, NULL, check_ev, phils))
		ft_close(phils, 7);
	if (pthread_detach(phils->philo->th_ate))
		ft_close(phils, 7);
}

void	ft_close(t_th_phil *phils, int err)
{
	int	i;

	i = -1;
	while (++i < phils->philo->num_phils)
		kill(phils[i].ph_p, 2);
	sem_close(phils->philo->forks);
	sem_close(phils->philo->forks);
	sem_unlink("forks");
	sem_unlink("mess");
	if (phils)
	{
		free(phils);
		phils = NULL;
	}
	exit(err);
}

void	*check_ev(void	*tmp_phils)
{
	t_th_phil	*phils;
	int			i;

	i = 0;
	phils = tmp_phils;
	while (i < phils->philo->num_phils)
	{
		sem_wait(phils->philo->ev_ate);
		i++;
	}
	sem_close(phils->philo->ev_ate);
	sem_unlink("everyone_ate");
	ft_close(phils, 0);
	return ((void *)0);
}

t_ull	get_time(t_philo *philo)
{
	gettimeofday(&philo->tv, NULL);
	return ((philo->tv.tv_sec * 1000) + \
	(philo->tv.tv_usec / 1000) - philo->start_t);
}
