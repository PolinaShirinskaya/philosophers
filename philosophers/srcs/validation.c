/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 03:35:13 by adian             #+#    #+#             */
/*   Updated: 2022/07/09 03:38:42 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int			i;
	int						s;
	long long				res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			s = -1;
	}
	while (ft_isdigit(str[i]))
	{
		if (res >= 214748364 && str[i] > 7 && s == 1)
			return (-1);
		if (res >= 214748364 && str[i] > 8 && s == -1)
			return (-1);
		res = res * 10 + (str[i++] - '0');
	}
	return ((int)(res * s));
}

static int	ft_is_str_digit(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_validation(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_str_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
