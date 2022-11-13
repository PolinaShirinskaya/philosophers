/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 03:29:38 by adian             #+#    #+#             */
/*   Updated: 2022/07/09 15:51:09 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	free_philos(t_src *s)
{
	int	i;

	i = 0;
	while (i <= s->count_philo)
		pthread_mutex_destroy(&s->philos[i++].monitor);
	i = 0;
	while (i <= s->count_philo)
		pthread_mutex_destroy(&s->forks[i++]);
	if (s->philos != NULL)
		free(s->philos);
	if (s->forks != NULL)
		free(s->forks);
	pthread_mutex_destroy(&s->print);
}

int	main(int argc, char **argv)
{
	t_src	s;

	if (argc < 5 || argc > 6 || !ft_validation(argc, argv))
	{
		printf(ERR_MESS_N);
		return (1);
	}
	if (!ft_init_philo(&s, argc, argv))
	{
		free_philos(&s);
		printf(ERR_MESS_S);
		return (1);
	}
	if (!ft_create_pth(&s))
		printf(ERR_MESS_S);
	free_philos(&s);
	return (0);
}
