#include "philo_bonus.h"

t_timespec time_get_now(void)
{
	t_timespec time;

	gettimeofday(&time, NULL);
	return (time);
}

size_t time_get_millis(t_timespec time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

size_t time_get_millis_now(void)
{
	return (time_get_millis(time_get_now()));
}

size_t time_get_millis_from_start(t_table *table)
{
	return (time_get_millis_now() - time_get_millis(table->time));
}

void ft_usleep(size_t usec)
{
	size_t current;

	current = time_get_millis_now();
	while (usec > time_get_millis_now() - current)
		usleep(usec * 10);
}
