#include "push_swap.h"

int	ft_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_duplicate(char **tab)
{
	int	pos;
	int	i;

	pos = 1;
	while (tab[pos])
	{
		i = pos + 1;
		while (tab[i])
		{
			if (!ft_strncmp(tab[pos], tab[i], 11))
			{
				write(1, ERROR, 6);
				exit(0);
			}
			i++;
		}		
		pos++;
	}
}

void	ft_error(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '-')
				j++;
			if (!ft_isdigit(tab[i][j]))
			{
				write(1, "Error1\n", 7);
				exit(0);
			}
			j++;
		}
		i++;
	}
	ft_duplicate(tab);
}