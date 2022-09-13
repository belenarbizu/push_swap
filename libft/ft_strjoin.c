/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:49:56 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:15:12 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		ts1;
	int		cnt;

	cnt = 0;
	if (!s1)
		return (0);
	ts1 = ft_strlen(s1);
	s = malloc((ts1 + ft_strlen(s2) + 1) * sizeof(void));
	if (!s)
		return (0);
	while (s1[cnt])
	{
		s[cnt] = s1[cnt];
		cnt++;
	}
	cnt = 0;
	while (s2[cnt])
	{
		s[ts1] = s2[cnt];
		cnt++;
		ts1++;
	}
	s[ts1] = '\0';
	return (s);
}
