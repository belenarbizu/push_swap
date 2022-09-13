/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:15:08 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:09:51 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	unsigned long	size;

	size = ft_strlen(s) + 1;
	str = (char *)s;
	while (size > 0)
	{	
		size--;
		if (str[size] == (char)c)
			return (str + size);
	}
	if ((char)c == '\0')
		return (str);
	return (0);
}
