/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:35:41 by youarzaz          #+#    #+#             */
/*   Updated: 2019/04/04 01:45:01 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_memindex(void *str, int c, size_t n)
{
	size_t i;

	i = 0;
	if (!c)
		return (-1);
	while (i < n)
		if (((unsigned char *)str)[i] == c)
			return (i);
	return (-1);
}
