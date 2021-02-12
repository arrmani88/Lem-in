/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:54:10 by youarzaz          #+#    #+#             */
/*   Updated: 2019/04/05 21:22:52 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!s[i])
		return (ft_strdup(""));
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		--len;
	tmp = ft_strnew(len - i + 1);
	if (tmp)
	{
		while (i <= len)
			tmp[j++] = s[i++];
		tmp[j] = '\0';
		return (tmp);
	}
	return (NULL);
}
