/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:46:52 by rantario          #+#    #+#             */
/*   Updated: 2022/04/26 16:04:48 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ************************* INCLUDES ************************* */
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

/* ************************ STRUCTURES ************************ */
typedef unsigned long long	t_ull;

typedef struct s_philo
{
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_time_eat;
	int				exit;
	t_ull			start_t;
	struct timeval	tv;
	pthread_t		th_die;
	pthread_mutex_t	mut_message;
	pthread_mutex_t	mut_eat_c;
	pthread_mutex_t	mut_exit;
}	t_philo;

typedef struct s_thr_philo
{
	pthread_t		philo_loop;
	pthread_mutex_t	mut_fork;
	pthread_mutex_t	mut_death;
	int				number;
	int				eat_num;
	t_ull			when_die;
	t_philo			*philo;
}	t_thr_philo;

/* ********************** CHECK / PARSE *********************** */
int			parser(int argc, char **argv, t_philo *philo);
int			ft_error(int err);
int			check_arg_space(char **args, int *i, int *j);
int			iterate_args(int argc, char **argv);

/* ************************** LIBFT *************************** */
int			ft_isdigit(int c);
int			ft_atoi(const char *str, int *overflow);
int			is_space(const char *str, int *sign, int *overflow);
void		print_message(t_thr_philo *philos, char *str, int flag);

/* ************************* THREADS ************************** */
int			create_threads(t_thr_philo *philos, t_philo *philo);

/* ************************** PHILOS ************************** */
t_thr_philo	*philo_init(int argc, char **argv, t_philo *philo);
void		philo_sleep(t_thr_philo *phil);
void		*philo_loop(void *phil);
void		thr_eating(t_thr_philo *tmp_phil);
int			philo_destroy(t_thr_philo *philos);
void		try_take_fork(pthread_mutex_t *mut_fork, t_thr_philo *philos);
void		*take_forks(t_thr_philo *tmp_phil);

/* ************************** DEATH *************************** */
void		*death_1(void *philos);
int			death_2(t_thr_philo *tmp_philos, t_ull ntime, int *i, int *neat);
void		*death_3(t_thr_philo *tmp_philos);

/* *************************** TIME *************************** */
void		ft_usleep(t_ull ms, t_thr_philo *philos);
t_ull		get_time(t_philo *philo);

#endif
