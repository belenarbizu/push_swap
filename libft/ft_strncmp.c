/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:11:14 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 11:38:27 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cnt;
	unsigned char	*str1;
	unsigned char	*str2;

	cnt = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (cnt < n)
	{
		if (str1[cnt] != str2[cnt])
			return (str1[cnt] - str2[cnt]);
		if (str1[cnt] == '\0' && str2[cnt] == '\0')
			return (0);
		cnt++;
	}
	return (0);
}
