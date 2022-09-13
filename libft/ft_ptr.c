/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:21:43 by barbizu-          #+#    #+#             */
/*   Updated: 2022/05/19 17:27:37 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lenght_ptr(unsigned long long p)
{
	int	cnt;

	cnt = 0;
	if (p <= 0)
		cnt++;
	while (p != 0)
	{
		cnt++;
		p /= 16;
	}
	return (cnt);
}

int	ft_hex_ptr(unsigned long long p)
{
	int	lenght;

	lenght = ft_lenght_ptr(p);
	if (p >= 16)
	{
		ft_hex_ptr(p / 16);
		ft_hex_ptr(p % 16);
	}
	else
	{
		if (p <= 9)
			ft_putchar_fd(p + '0', 1);
		else
			ft_putchar_fd(p - 10 + 'a', 1);
	}
	return (lenght);
}

int	ft_ptr(unsigned long long p)
{
	int	lenght;

	lenght = 2;
	lenght = write(1, "0x", 2);
	lenght += ft_hex_ptr(p);
	return (lenght);
}
