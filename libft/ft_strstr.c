/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:19:04 by youarzaz          #+#    #+#             */
/*   Updated: 2019/03/29 23:50:24 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char *a;
	char *b;

	b = (char *)to_find;
	if (!*b)
	{
		return ((char *)str);
	}
	while (*str)
	{
		if (*str != *b)
		{
			str++;
			continue;
		}
		a = (char *)str;
		while (*a++ == *b++)
		{
			if (!*b)
				return ((char *)str);
		}
		b = (char *)to_find;
		str++;
	}
	return (NULL);
}
