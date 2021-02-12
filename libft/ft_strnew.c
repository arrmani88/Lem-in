/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:59:47 by youarzaz          #+#    #+#             */
/*   Updated: 2019/03/30 14:04:08 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *tmp;

	tmp = (char *)ft_memalloc(size + 1);
	if (tmp)
	{
		tmp = (char *)ft_memset(tmp, '\0', size + 1);
		return (tmp);
	}
	return (NULL);
}
