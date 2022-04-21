#include "philo.h"

int	check_args(int ac, char **av)
{
	int	i;

	if (ac < 1 + MIN_ARGS)
		return (print_err("parser", "too few arguments.", 0));
	if (ac > 1 + MAX_ARGS)
		return (print_err("parser", "too much arguments.", 0));
	i = 0;
	while (++i < ac)
	{
		if (!check_int(av[i]))
			return (print_err("parser", "argument should be numeric.", 0));
		if (!check_negative(av[i]))
			return (print_err("parser", "argument should be positive.", 0));
	}
	return (1);
}

int	check_int(const char *str)
{
	int		nbr;
	size_t	digits;
	size_t	i;

	i = 0;
	nbr = 0;
	digits = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		digits++;
		if ((nbr * 10 + (str[i] - '0')) / 10 != nbr)
			return (0);
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (!str[i] && digits);
}

int	check_negative(const char *str)
{
	size_t	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		return (0);
	return (1);
}
