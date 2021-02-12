/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:41:29 by youarzaz          #+#    #+#             */
/*   Updated: 2019/04/13 23:52:04 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			s;
	long long	res;

	s = 1;
	res = 0;
	while (*str == '\v' || *str == '\r' || *str == '\f'
			|| *str == ' ' || *str == '\n' || *str == '\t')
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (ft_ifcount((char *)str, &ft_isdigit) > 18)
		return ((s > 0) ? -1 : 0);
	while (*str && *str >= '0' && *str <= '9')
	{
		res = (res * 10) + *(str++) - '0';
		if (res > LONG_MAX || res < LONG_MIN)
			return ((s > 0) ? -1 : 0);
	}
	return ((int)(res * s));
}
