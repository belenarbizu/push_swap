/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:28:49 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:26:48 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cnt);
}

static char	*ft_copy2(char const *s, char c)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_copy(int i, char const *s, char c, char **tab)
{
	tab[i] = ft_copy2(s, c);
	if (!tab[i])
	{
		while (i > 0)
		{
			i--;
			free(tab[i]);
		}
		free(tab);
		return (0);
	}
	return (tab[i]);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	tab = (char **)malloc(sizeof(char *) * count + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			tab[i] = ft_copy(i, s, c, tab);
		while (*s && *s != c)
			s++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
