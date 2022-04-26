/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:05:14 by rantario          #+#    #+#             */
/*   Updated: 2022/04/26 16:07:03 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ull	get_time(t_philo *philo)
{
	gettimeofday(&philo->tv, NULL);
	return ((philo->tv.tv_sec * 1000) + \
	(philo->tv.tv_usec / 1000) - philo->start_t);
}

void	ft_usleep(t_ull ms, t_thr_philo *philos)
{
	t_ull	ms_end;
	t_ull	ms_now;

	gettimeofday(&philos->philo->tv, NULL);
	ms_now = (philos->philo->tv.tv_sec * 1000) + \
	(philos->philo->tv.tv_usec / 1000);
	ms_end = ms_now + ms;
	while (ms_now < ms_end)
	{
		gettimeofday(&philos->philo->tv, NULL);
		ms_now = (philos->philo->tv.tv_sec * 1000) + \
		(philos->philo->tv.tv_usec / 1000);
		usleep(100);
	}
}
