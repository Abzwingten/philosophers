#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_table	*table;

	table = parse(ac, av);
	if (table != NULL)
	{
		threads_start(table);
		threads_wait(table);
	}
	return (0);
}
