/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 04:03:50 by malibert          #+#    #+#             */
/*   Updated: 2019/04/15 06:05:45 by malibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		pos_y(char **tab)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (b <= 3)
	{
		while (a <= 3)
		{
			if (tab[b][a] == '#')
				return (b);
			a++;
		}
		a = 0;
		b++;
	}
	return (0);
}

int		pos_x(char **tab)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (a <= 3)
	{
		while (b <= 3)
		{
			if (tab[b][a] == '#')
				return (a);
			b++;
		}
		b = 0;
		a++;
	}
	return (0);
}

char	**final(char **tab, int h, int w)
{
	char	**piece;
	int		x;
	int		y;
	int		new_x;
	int		new_y;

	x = -1;
	piece = (char **)malloc(sizeof(char *) * (w));
	while (++x < 4)
		piece[x] = (char *)malloc(sizeof(char) * (h));
	new_x = pos_x(tab);
	new_y = pos_y(tab);
	x = 0;
	y = 0;
	while (y <= h)
	{
		while (x <= w)
		{
			piece[y][x] = tab[new_y][new_x];
			x++;
			new_x++;
		}
		x = 0;
		new_x = 0;
		y++;
		new_y++;
	}
	free(tab);
	return (piece);
}

