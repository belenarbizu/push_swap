/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:04:20 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:08:52 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*s;
	size_t	i;
	size_t	r;
	size_t	tam1;
	size_t	tam2;

	s = (char *)src;
	i = 0;
	r = 0;
	tam1 = ft_strlen(dst);
	tam2 = ft_strlen(s);
	if (dstsize > tam1)
		r = tam1 + tam2;
	else
		r = tam2 + dstsize;
	while (s[i] && (tam1 + 1) < dstsize)
	{
		dst[tam1] = s[i];
		tam1++;
		i++;
	}
	dst[tam1] = '\0';
	return (r);
}
