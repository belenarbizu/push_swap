/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:49:55 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:08:35 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;
	int		tam;
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	tam = 0;
	cnt = 0;
	while (s[tam])
		tam++;
	if (dstsize < 1)
		return (tam);
	while (s[cnt] && cnt < dstsize - 1)
	{
		d[cnt] = s[cnt];
		cnt++;
	}
	d[cnt] = '\0';
	return (tam);
}
