/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:40:28 by youarzaz          #+#    #+#             */
/*   Updated: 2019/04/07 19:15:16 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_alloc(int n)
{
	size_t size;

	size = 1;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			size;
	unsigned int	nbr;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_itoa_alloc(n);
	str = ft_strnew(size - 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	nbr = (n < 0) ? -n : n;
	str[--size] = '\0';
	while (size-- && nbr)
	{
		str[size] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
