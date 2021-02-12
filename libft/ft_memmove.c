/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:28:48 by youarzaz          #+#    #+#             */
/*   Updated: 2019/03/31 22:44:29 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*srccopy;

	srccopy = (char *)src;
	i = -1;
	if (src < dest)
	{
		while ((int)--n >= 0)
			*((char *)dest + n) = *(srccopy + n);
	}
	else
	{
		while ((int)++i < (int)n)
			*((char *)dest + i) = *(srccopy + i);
	}
	return (dest);
}
