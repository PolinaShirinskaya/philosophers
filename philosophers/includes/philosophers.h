/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:36:39 by adian             #+#    #+#             */
/*   Updated: 2022/07/10 07:31:02 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define ERR_MESS_N "Error: Not valid args\n"
# define ERR_MESS_S "Error\n"

typedef struct s_philo
{
	pthread_t		tid;
	int				id;
	int				count_eat;
	unsigned long	last_eat;
	int				l_fork;
	int				r_fork;
	pthread_mutex_t	monitor;
	struct s_src	*s;
}	t_philo;

typedef struct s_src
{
	int				count_philo;
	unsigned long	time_die;
	unsigned long	time_eat;
	unsigned long	time_sleep;
	unsigned long	time_start;
	int				max_eat;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_src;

/* validation */
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				ft_validation(int ac, char **av);

/* init */
int				ft_init_philo(t_src *s, int argc, char **argv);

/* print messege */
unsigned long	ft_get_actual_time(void);
void			ft_print_mess(t_philo *p, char *str);

/* utils */
int				ft_get_min_max(int a, int b, char *min_or_max);

/* monitor and create threads */
int				ft_create_pth(t_src *s);
int				ft_detach_all(t_src *s);

/* action */
void			*ft_gate_actions(void *p_v);

#endif