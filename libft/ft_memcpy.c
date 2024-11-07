/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:43:56 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:07:57 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	cnt;

	d = (char *)dst;
	s = (char *)src;
	cnt = 0;
	if (!d && !s)
		return (0);
	while (cnt < n)
	{
		d[cnt] = s[cnt];
		cnt++;
	}
	return (d);
}
