/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messege.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:17:35 by adian             #+#    #+#             */
/*   Updated: 2022/07/10 17:29:32 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_print_mess(t_philo *p, char *str)
{
	unsigned long	tm;

	pthread_mutex_lock(&p->s->print);
	if (p->s->max_eat != -2 && p->count_eat == p->s->max_eat)
		usleep(4221);
	tm = ft_get_actual_time() - p->s->time_start;
	printf("%ld %d %s\n", tm, p->id + 1, str);
	pthread_mutex_unlock(&p->s->print);
}
