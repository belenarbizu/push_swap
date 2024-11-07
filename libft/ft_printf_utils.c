/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:39:32 by barbizu-          #+#    #+#             */
/*   Updated: 2022/05/19 17:27:05 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	cnt;

	cnt = 0;
	if (s)
	{
		while (s[cnt])
		{
			write(1, &s[cnt], 1);
			cnt++;
		}
	}
	else
	{
		ft_putstr("(null)");
		return (6);
	}
	return (cnt);
}

int	ft_lenght_hex(unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n <= 0)
		cnt++;
	while (n != 0)
	{
		cnt++;
		n /= 16;
	}
	return (cnt);
}

int	ft_hexadecimal(unsigned int n, const char str)
{
	int	lenght;

	lenght = ft_lenght_hex(n);
	if (n >= 16)
	{
		ft_hexadecimal(n / 16, str);
		ft_hexadecimal(n % 16, str);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
		{
			if (str == 'x')
				ft_putchar_fd(n - 10 + 'a', 1);
			else
				ft_putchar_fd(n - 10 + 'A', 1);
		}
	}
	return (lenght);
}

int	ft_putnbr(int n)
{
	char	*s;
	int		lenght;

	s = ft_itoa(n);
	lenght = ft_putstr(s);
	free(s);
	return (lenght);
}
