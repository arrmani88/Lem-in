/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:24:31 by youarzaz          #+#    #+#             */
/*   Updated: 2019/03/30 21:26:04 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		tmp = ft_strnew(ft_strlen(s));
		if (tmp)
		{
			while (s[i])
			{
				tmp[i] = f(i, s[i]);
				i++;
			}
			tmp[i] = '\0';
			return (tmp);
		}
	}
	return (NULL);
}
