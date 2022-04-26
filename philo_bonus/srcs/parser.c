#include "philo_bonus.h"

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
	philo->num_philos = ft_atoi(argv[i++], &overflow);
	philo->time_die = ft_atoi(argv[i++], &overflow);
	philo->time_eat = ft_atoi(argv[i++], &overflow);
	philo->time_sleep = ft_atoi(argv[i++], &overflow);
	if (argc == 6)
		philo->num_time_eat = ft_atoi(argv[i++], &overflow);
	else
		philo->num_time_eat = -555;
	if (!philo->num_philos || !philo->time_die || !philo->time_eat \
	|| !philo->time_sleep || !philo->num_time_eat)
		return (ft_error(7));
	if (overflow)
		return (ft_error(9));
	return (0);
}

int	check_arg_space(char **args, int *i, int *j)
{
	if (!args[*i][0])
		return (1);
	while (args[*i][*j] == ' ' || \
			(args[*i][*j] >= '\t' && args[*i][*j] <= '\r'))
		(*j)++;
	if (args[*i][*j] == '-' || args[*i][*j] == '+')
	{
		(*j)++;
	}
	return (0);
}

int	iterate_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (check_arg_space(argv, &i, &j))
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
