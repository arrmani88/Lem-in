/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:13:41 by youarzaz          #+#    #+#             */
/*   Updated: 2019/03/29 23:41:15 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void *tmp;

	tmp = ft_memchr(src, c, n);
	if (tmp)
	{
		dest = ft_memcpy(dest, src, tmp - src + 1);
		return (ft_memchr(dest, c, n) + 1);
	}
	ft_memcpy(dest, src, n);
	return (NULL);
}
