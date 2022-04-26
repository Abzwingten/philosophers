/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:06:36 by rantario          #+#    #+#             */
/*   Updated: 2022/04/26 16:06:37 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_process(t_thr_philo *philos)
{
	int	ph_ate;

	ph_ate = 0;
	if (pthread_create(&philos->th_die, NULL, when_die, philos))
		exit(5);
	if (pthread_detach(philos->th_die))
		exit(5);
	if (pthread_mutex_init(&philos->mut_death, NULL))
		exit(5);
	if (philos->number % 2)
		ft_usleep(philos->philo->time_eat, philos);
	while (1)
	{
		philo_eat(philos, &ph_ate);
		if (sem_post(philos->philo->forks) || sem_post(philos->philo->forks))
			exit(5);
		print_message(philos, "is sleeping", 1);
		ft_usleep(philos->philo->time_sleep, philos);
		print_message(philos, "is thinking", 1);
	}
	exit(0);
}

void	philo_eat(t_thr_philo *philos, int *ph_ate)
{
	if (sem_wait(philos->philo->forks))
		exit(5);
	print_message(philos, "has taken a fork", 1);
	if (sem_wait(philos->philo->forks))
		exit(5);
	print_message(philos, "has taken a fork", 1);
	pthread_mutex_lock(&philos->mut_death);
	philos->when_die += philos->philo->time_die;
	pthread_mutex_unlock(&philos->mut_death);
	print_message(philos, "is eating", 1);
	if (philos->philo->num_time_eat != -555 \
		&& *ph_ate < philos->philo->num_time_eat)
		(*ph_ate)++;
	if (philos->philo->num_time_eat != -555 \
		&& *ph_ate == philos->philo->num_time_eat)
	{
		if (sem_post(philos->philo->ev_ate))
			exit(5);
		(*ph_ate)++;
	}
	ft_usleep(philos->philo->time_eat, philos);
}

void	*when_die(void *tmp_phil)
{
	t_thr_philo	*phil;

	phil = tmp_phil;
	while (1)
	{
		pthread_mutex_lock(&phil->mut_death);
		if (phil->when_die <= get_time(phil->philo))
		{
			print_message(phil, "died", 0);
			exit(0);
			break ;
		}
		pthread_mutex_unlock(&phil->mut_death);
		usleep(100);
	}
	return (NULL);
}

void	th_ate(t_thr_philo *philos)
{
	if (pthread_create(&philos->philo->th_ate, NULL, check_ev, philos))
		ft_close(philos, 7);
	if (pthread_detach(philos->philo->th_ate))
		ft_close(philos, 7);
}
