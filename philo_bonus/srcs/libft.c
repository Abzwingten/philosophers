/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:06:22 by rantario          #+#    #+#             */
/*   Updated: 2022/04/26 16:06:57 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str, int *overflow)
{
	size_t			i;
	int				sign;
	unsigned long	result;

	result = 0;
	sign = 1;
	i = is_space(str, &sign, overflow);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i ++;
		if (result > INT_MAX)
			break ;
	}
	if (result > INT_MAX && sign == 1)
		*overflow = 1;
	if (result > INT_MAX && sign == -1)
		*overflow = 1;
	return ((int)result * sign);
}

int	is_space(const char *str, int *sign, int *overflow)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i ++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i ++;
		*overflow = 2;
	}
	return (i);
}

int	ft_error(int err)
{
	printf("invalid arguments\n");
	return (err);
}

void	print_message(t_thr_philo *philos, char *str, int flag)
{
	if (sem_wait(philos->philo->message))
		exit(7);
	printf("%llu %d %s\n", get_time(philos->philo), philos->number, str);
	if (flag)
	{
		if (sem_post(philos->philo->message))
			exit(7);
	}
}
