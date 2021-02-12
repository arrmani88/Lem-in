/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:11:23 by youarzaz          #+#    #+#             */
/*   Updated: 2019/03/29 00:48:02 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int n;

	n = ft_strlen(s);
	if (!c)
		return ((char *)s + n);
	--n;
	while (n > -1)
	{
		if (((unsigned char)s[n]) == (char)c)
			return ((char *)s + n);
		n--;
	}
	return (NULL);
}
