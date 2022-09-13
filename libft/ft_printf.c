/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:08:55 by barbizu-          #+#    #+#             */
/*   Updated: 2022/05/19 17:29:02 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_lenght_un(unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n <= 0)
		cnt++;
	while (n != 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

int	ft_formats(va_list args, char str)
{
	int	lenght;

	lenght = 0;
	if (str == 'c')
		lenght = ft_putchar(va_arg(args, int));
	else if (str == 's')
		lenght = ft_putstr(va_arg(args, char *));
	else if (str == 'p')
		lenght = ft_ptr(va_arg(args, unsigned long long));
	else if (str == 'd' || str == 'i')
		lenght = ft_putnbr(va_arg(args, int));
	else if (str == 'u')
		lenght = ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (str == 'x' || str == 'X')
		lenght = ft_hexadecimal(va_arg(args, unsigned int), str);
	else if (str == '%')
		lenght = ft_percent();
	return (lenght);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		cnt;
	int		lenght;
	char	*s;

	s = (char *)str;
	cnt = 0;
	lenght = 0;
	va_start(args, str);
	while (str[cnt])
	{
		if (str[cnt] == '%')
		{
			lenght += ft_formats(args, str[cnt + 1]);
			cnt++;
		}
		else
			lenght += ft_putchar(str[cnt]);
		cnt++;
	}
	va_end(args);
	return (lenght);
}
