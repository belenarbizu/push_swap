/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:45:26 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:14:34 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	cnt;

	cnt = 0;
	while (src[cnt] != '\0')
	{
		dest[cnt] = src[cnt];
		++cnt;
	}
	dest[cnt] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*d;

	s = (char *)s1;
	d = malloc(ft_strlen(s) + 1);
	if (!d)
		return (0);
	ft_strcpy(d, s);
	return (d);
}
