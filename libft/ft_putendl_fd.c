/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:40:10 by barbizu-          #+#    #+#             */
/*   Updated: 2022/04/29 10:34:11 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	cnt;

	cnt = 0;
	if (s)
	{
		while (s[cnt])
		{
			write(fd, &s[cnt], 1);
			++cnt;
		}
		write(fd, "\n", 1);
	}
}
