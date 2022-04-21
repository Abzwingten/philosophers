/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:48:00 by rantario          #+#    #+#             */
/*   Updated: 2022/04/21 18:48:01 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_use_fork(t_philo *philo,
					int (*sem_action)(), char *message)
{
	sem_action(philo->table->forks);
	print(philo, message);
	sem_action(philo->table->forks);
	print(philo, message);
}

void	philo_eat(t_philo *philo)
{
	philo_use_fork(philo, sem_wait, HAS_TAKEN_A_FORK);
	philo->last_eat = time_get_millis_now();
	print(philo, IS_EATING);
	philo->eating = 1;
	ft_usleep(philo->table->time_to_eat);
	philo->eating = 0;
	philo->n_eat++;
	philo_use_fork(philo, sem_post, NULL);
}

void	philo_sleep(t_philo *philo)
{
	philo->sleeping = 1;
	print(philo, IS_SLEEPING);
	ft_usleep(philo->table->time_to_sleep);
	philo->sleeping = 0;
}

void	philo_think(t_philo *philo)
{
	print(philo, IS_THINKING);
}
