/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:26:30 by barbizu-          #+#    #+#             */
/*   Updated: 2022/05/19 17:29:44 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_itoa_un(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_lenght_un(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		lenght;
	char	*s;

	s = ft_itoa_un(n);
	lenght = ft_putstr(s);
	free(s);
	return (lenght);
}
