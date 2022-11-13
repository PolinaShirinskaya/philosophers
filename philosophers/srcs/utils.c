/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 03:52:22 by adian             #+#    #+#             */
/*   Updated: 2022/07/10 17:29:00 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

unsigned long	ft_get_actual_time(void)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * 1000 + tm.tv_usec / 1000));
}

int	ft_get_min_max(int a, int b, char *min_or_max)
{
	if ('i' == min_or_max[1])
	{
		if (a > b)
			return (b);
		return (a);
	}
	if (a < b)
		return (b);
	else if (a > b)
		return (a);
	if (a == b)
		return (0);
	return (-1);
}
