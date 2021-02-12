/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:07:22 by youarzaz          #+#    #+#             */
/*   Updated: 2019/03/28 20:05:46 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = dest;
	while (*tmp)
		tmp++;
	while (*src && i++ < n)
		*(tmp++) = *(src++);
	*tmp = '\0';
	return (dest);
}
