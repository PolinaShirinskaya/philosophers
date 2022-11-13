/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_monitor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:05:17 by adian             #+#    #+#             */
/*   Updated: 2022/07/09 15:26:17 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	ft_food_limit(t_src *s, int id)
{
	pthread_mutex_lock(&s->philos[id].monitor);
	if (s->philos[id].count_eat >= s->max_eat)
	{
		printf("%lu %d is eating\n", ft_get_actual_time() \
			- s->time_start, s->philos[id].id + 1);
		pthread_mutex_unlock(&s->philos[id].monitor);
		return (1);
	}
	pthread_mutex_unlock(&s->philos[id].monitor);
	return (0);
}

static int	ft_isdie(t_philo *p)
{
	pthread_mutex_lock(&p->monitor);
	if (ft_get_actual_time() - p->last_eat > p->s->time_die + 5)
		return (1);
	pthread_mutex_unlock(&p->monitor);
	return (0);
}

static void	ft_monitor(t_src *s)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == s->count_philo)
			i = 0;
		if (ft_isdie(&s->philos[i]))
		{
			pthread_mutex_lock(&s->print);
			pthread_mutex_unlock(&s->philos[i].monitor);
			printf("%lu %d is died\n", ft_get_actual_time() \
				- s->time_start, s->philos[i].id + 1);
			break ;
		}
		else if (-2 != s->max_eat)
		{
			if (ft_food_limit(s, i))
				break ;
		}
		i++;
	}
}

int	ft_create_pth(t_src *s)
{
	int	i;

	i = 0;
	while (i < s->count_philo)
	{
		if (pthread_create(&s->philos[i].tid, NULL, &ft_gate_actions,
				(void *)&s->philos[i]))
			return (0);
		pthread_detach(s->philos[i].tid);
		i++;
		if (i % 2)
			usleep(42);
	}
	ft_monitor(s);
	return (1);
}
