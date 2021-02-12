/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:03:35 by youarzaz          #+#    #+#             */
/*   Updated: 2019/03/28 19:01:00 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *tmp;

	tmp = dest;
	while (*tmp)
		tmp++;
	while (*src)
		*(tmp++) = *(src++);
	*tmp = '\0';
	return (dest);
}
