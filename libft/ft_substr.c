/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:20:34 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:14:56 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;

	n = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(*s) * len + 1);
	if (!str)
		return (NULL);
	if (start <= ft_strlen(s))
	{	
		while (n < len && s[start])
		{
			str[n] = s[start];
			start++;
			n++;
		}
	}
	str[n] = '\0';
	return (str);
}
