/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 03:39:51 by adian             #+#    #+#             */
/*   Updated: 2022/07/09 15:50:28 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	ft_init_argv(t_src *s, int argc, char **argv)
{
	s->philos = NULL;
	s->forks = NULL;
	s->count_philo = ft_atoi(argv[1]);
	s->time_die = ft_atoi(argv[2]);
	s->time_eat = ft_atoi(argv[3]);
	s->time_sleep = ft_atoi(argv[4]);
	s->max_eat = -2;
	if (argc == 6)
		s->max_eat = ft_atoi(argv[5]);
	s->time_start = ft_get_actual_time();
	s->philos = (t_philo *)malloc(sizeof(t_philo) * s->count_philo);
	s->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
				* s->count_philo);
	if (!s->philos || !s->forks || s->count_philo < 1 || s->time_die < 1 \
		|| s->time_eat < 1 || s->time_sleep < 1)
		return (0);
	if (-2 != s->max_eat && s->max_eat < 1)
		return (0);
	s->time_eat *= 1000;
	s->time_sleep *= 1000;
	return (1);
}

int	ft_init_philo(t_src *s, int argc, char **argv)
{
	int	i;

	i = 0;
	if (!ft_init_argv(s, argc, argv))
		return (0);
	if (pthread_mutex_init(&s->print, NULL) != 0)
		return (0);
	while (i < s->count_philo)
	{
		s->philos[i].id = i;
		s->philos[i].count_eat = 0;
		s->philos[i].last_eat = s->time_start;
		s->philos[i].s = s;
		s->philos[i].l_fork = i;
		s->philos[i].r_fork = (i + 1) % s->count_philo;
		if (pthread_mutex_init(&s->philos[i].monitor, NULL) != 0)
			return (0);
		if (pthread_mutex_init(&s->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
