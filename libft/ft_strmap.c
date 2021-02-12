/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:13:15 by youarzaz          #+#    #+#             */
/*   Updated: 2019/03/30 21:30:21 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	i = 0;
	if (s && f)
	{
		tmp = ft_strnew(ft_strlen(s));
		if (tmp)
		{
			while (s[i])
			{
				tmp[i] = f(s[i]);
				i++;
			}
			tmp[i] = '\0';
			return (tmp);
		}
	}
	return (NULL);
}
