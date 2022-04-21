/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:48:16 by rantario          #+#    #+#             */
/*   Updated: 2022/04/21 18:48:17 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print(t_philo *philo, char *message)
{
	if (message != NULL && philo->table->is_printing != NULL)
	{
		sem_wait(philo->table->is_printing);
		if (!philo->table->death)
			printf("%zu %zu %s\n", \
				time_get_millis_from_start(philo->table), \
				philo->id, \
				message \
			);
		sem_post(philo->table->is_printing);
	}
}

int	print_err(char *where, char *message, int code)
{
	printf("philo: %s: %s\n", where, message);
	return (code);
}
