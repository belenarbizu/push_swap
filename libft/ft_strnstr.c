/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:06:49 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:12:56 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cnt;
	size_t	cnt2;
	char	*s;
	char	*d;

	s = (char *)haystack;
	d = (char *)needle;
	cnt = 0;
	cnt2 = 0;
	if (d[cnt] == '\0')
		return (s);
	while (cnt < len && s[cnt])
	{
		while (s[cnt + cnt2] == d[cnt2] && d[cnt2] != '\0' && cnt + cnt2 < len)
			cnt2++;
		if (d[cnt2] == '\0')
			return (s + cnt);
		cnt2 = 0;
		cnt++;
	}
	return (0);
}
