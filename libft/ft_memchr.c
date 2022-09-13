/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:10:17 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:12:14 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	cnt;

	str = (char *)s;
	cnt = 0;
	while (cnt < n)
	{
		if (*str == (char)c)
			return (str);
		str++;
		cnt++;
	}
	return (0);
}
