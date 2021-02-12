/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:26:31 by youarzaz          #+#    #+#             */
/*   Updated: 2019/04/09 16:46:25 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	l;
	char	*a;

	a = (char *)str;
	i = 0;
	n++;
	l = n;
	if (!*to_find)
		return ((char *)str);
	while (*str && n)
	{
		if (*to_find != *str && --n)
		{
			str++;
			continue ;
		}
		while (to_find[i++] == *(str++) && --n)
			if (!*(to_find + i))
				return ((char *)str - i);
		str = ++a;
		n = --l;
		i = 0;
	}
	return (NULL);
}
