/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:19:10 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:07:37 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	cnt;
	char	*str;

	str = (char *)s;
	cnt = 0;
	if (n > 0)
	{
		while (cnt < n)
		{
			str[cnt] = '\0';
			cnt++;
		}
	}
}
