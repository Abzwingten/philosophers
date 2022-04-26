#include "philosophers_bonus.h"

int	ft_atoi(const char *str, int *overflow)
{
	size_t			i;
	int				sign;
	unsigned long	result;

	result = 0;
	sign = 1;
	i = skipp(str, &sign, overflow);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i ++;
		if (result > 2147483650)
			break ;
	}
	if (result > 2147483647 && sign == 1)
		*overflow = 1;
	if (result > 2147483648 && sign == -1)
		*overflow = 1;
	return ((int)result * sign);
}

int	skipp(const char *str, int *sign, int *overflow)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i ++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i ++;
		*overflow = 2;
	}
	return (i);
}

int	ft_init(int argc, char **argv, t_philo *philo, t_th_phil **phils)
{
	if (parser(argc, argv, philo))
		return (3);
	*phils = (t_th_phil *)malloc(sizeof(t_th_phil) * philo->num_phils);
	if (!*phils)
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
			ft_close(*phils, 5);
	}
	philo->forks = sem_open("forks", O_CREAT, S_IRWXG, philo->num_phils);
	philo->mess = sem_open("mess", O_CREAT, S_IRWXG, 1);
	if (philo->forks == SEM_FAILED || philo->mess == SEM_FAILED)
		ft_close(*phils, 5);
	return (0);
}
