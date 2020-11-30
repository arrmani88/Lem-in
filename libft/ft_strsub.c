/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:04:31 by anel-bou          #+#    #+#             */
/*   Updated: 2020/10/29 11:02:25 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s || !(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new = ft_strncpy(new, (const char *)s + start, len);
	new[len] = '\0';
	return (new);
}
