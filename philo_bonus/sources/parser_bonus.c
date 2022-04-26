#include "philosophers_bonus.h"

int	parser(int argc, char **argv, t_philo *philo)
{
	int	i;
	int	overflow;

	i = 1;
	overflow = 0;
	if (argc != 5 && argc != 6)
		return (ft_error(2));
	if (verify_argv(argc, argv))
		return (3);
	philo->num_phils = ft_atoi(argv[i++], &overflow);
	philo->time_die = ft_atoi(argv[i++], &overflow);
	philo->time_eat = ft_atoi(argv[i++], &overflow);
	philo->time_sleep = ft_atoi(argv[i++], &overflow);
	if (argc == 6)
		philo->num_time_eat = ft_atoi(argv[i++], &overflow);
	else
		philo->num_time_eat = -555;
	if (!philo->num_phils || !philo->time_die || !philo->time_eat \
	|| !philo->time_sleep || !philo->num_time_eat)
		return (ft_error(7));
	if (overflow)
		return (ft_error(9));
	return (0);
}

int	ft_error(int err)
{
	printf("invalid arguments\n");
	return (err);
}

int	verify_argv2(char **nums, int *i, int *j)
{
	if (!nums[*i][0])
		return (1);
	while (nums[*i][*j] == ' ' || nums[*i][*j] == '\t' || nums[*i][*j] == '\n'
		|| nums[*i][*j] == '\v' || nums[*i][*j] == '\f' || nums[*i][*j] == '\r')
		(*j)++;
	if (nums[*i][*j] == '-' || nums[*i][*j] == '+')
	{
		(*j)++;
	}
	return (0);
}

int	verify_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (verify_argv2(argv, &i, &j))
			return (ft_error(3));
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (ft_error(5));
			j++;
		}
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
