/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:05:23 by rantario          #+#    #+#             */
/*   Updated: 2022/04/26 16:05:51 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

/* ************************* INCLUDES ************************* */
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>
# include <limits.h>

/* ************************ STRUCTURES ************************ */
typedef unsigned long long	t_ull;

typedef struct s_philo {
	int					num_philos;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					num_time_eat;
	t_ull				start_t;
	struct timeval		tv;
	pthread_t			th_ate;
	pthread_mutex_t		mt_ate;
	sem_t				*forks;
	sem_t				*message;
	sem_t				*ev_ate;
}	t_philo;

typedef struct s_thr_philo {
	int					number;
	pid_t				ph_p;
	t_ull				when_die;
	pthread_t			th_die;
	pthread_mutex_t		mut_death;
	t_philo				*philo;
}	t_thr_philo;

/* ********************** CHECK / PARSE *********************** */
int			parser(int argc, char **argv, t_philo *philo);
int			check_arg_space(char **args, int *i, int *j);
int			iterate_args(int argc, char **argv);

/* ************************** LIBFT *************************** */
int			ft_error(int err);
int			ft_isdigit(int c);
int			ft_atoi(const char *str, int *overflow);
int			is_space(const char *str, int *sign, int *overflow);
void		print_message(t_thr_philo *philos, char *str, int flag);

/* ************************** PHILOS ************************** */
void		philo_process(t_thr_philo *philos);
int			philo_init(int argc, char **argv, t_philo *philo, \
						t_thr_philo **philos);
void		ft_close(t_thr_philo *philos, int err);
void		*check_ev(void	*tmp_philos);
void		th_ate(t_thr_philo *philos);
void		philo_eat(t_thr_philo *philos, int *ph_ate);

/* ************************** DEATH *************************** */
void		*when_die(void *tmp_phil);
int			ph_dead(t_thr_philo *philos);

/* *************************** TIME *************************** */
t_ull		get_time(t_philo *philo);
void		ft_usleep(t_ull ms, t_thr_philo *philos);

#endif
