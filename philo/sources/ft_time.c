/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:47:28 by rantario          #+#    #+#             */
/*   Updated: 2022/04/21 18:47:29 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct timeval	time_get_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time);
}

size_t	time_get_millis(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

size_t	time_get_millis_now(void)
{
	return (time_get_millis(time_get_now()));
}

size_t	time_get_millis_from_start(t_table *table)
{
	return (time_get_millis_now() - time_get_millis(table->time));
}

void	ft_usleep(size_t usec)
{
	size_t	current;

	current = time_get_millis_now();
	while (time_get_millis_now() < current + usec)
		usleep(usec * 10);
}
