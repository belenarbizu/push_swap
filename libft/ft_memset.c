/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:59:57 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:07:22 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t	cnt;
	char	*d;

	d = (char *)dest;
	cnt = 0;
	while (cnt < len)
	{
		d[cnt] = (unsigned char)c;
		cnt++;
	}
	return (d);
}
