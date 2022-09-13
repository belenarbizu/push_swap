/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:35:13 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:12:38 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n)
	{
		if (((unsigned char *)s1)[cnt] != (((unsigned char *)s2)[cnt]))
			return (((unsigned char *)s1)[cnt] - (((unsigned char *)s2)[cnt]));
		cnt++;
	}
	return (0);
}
