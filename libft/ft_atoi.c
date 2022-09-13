/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:23:55 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:13:13 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		n;
	int		cnt;
	int		sign;

	cnt = 0;
	n = 0;
	sign = 1;
	while (str[cnt] == ' ' || str[cnt] == '\t' || str[cnt] == '\n'
		|| str[cnt] == '\v' || str[cnt] == '\f' || str[cnt] == '\r')
		cnt++;
	if (str[cnt] == '-' || str[cnt] == '+')
	{
		if (str[cnt] == '-')
			sign = -1;
		cnt++;
	}
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		n = n * 10 + str[cnt] - '0';
		cnt++;
	}
	return (n * sign);
}
