/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:13:18 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:15:41 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	len;
	int	cnt;

	len = ft_strlen(s1);
	cnt = 0;
	while (cnt < len && !(ft_strchr(set, s1[cnt]) == 0))
		cnt++;
	return (cnt);
}

static int	ft_end(char const *s1, char const *set)
{
	int	len;

	len = ft_strlen(s1);
	while (len > 0 && !(ft_strchr(set, s1[len - 1]) == 0))
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
