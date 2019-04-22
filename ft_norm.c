/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 11:54:03 by malibert          #+#    #+#             */
/*   Updated: 2019/04/22 12:27:09 by malibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_shift(char *str)
{
	int i;

	if (ft_strcmp(str, "....") != 0)
	{
		i = 0;
		while (i < 3)
		{
			str[i] = str[i + 1];
			i++;
		}
		str[i] = '.';
	}
}

int		ft_chk(char **tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tab[i][0] != '.')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_left(char **tab)
{
	intnb;
	inti;

	i = 0;
	nb = 1;
	while (nb)
	{
		if (ft_chk(tab) == 0)
		{
			while (i < 4)
			{
				ft_shift(tab[i]);
				i++;
			}
			i = 0;
		}
		else
		{
			nb = 0;
		}
	}
	return (tab);
}

char	**ft_up(char **tab)	
{
	intnb;
	inti;

	i = 0;
	nb = 1;
	while (nb)
	{
		if (ft_strcmp(tab[0], "....") == 0)
		{
			free(tab[0]);
			tab[0] = tab[1];
			tab[1] = tab[2];
			tab[2] = tab[3];
			tab[3] = ft_strdup("....");
		}
		else
		{
			nb = 0;
		}
	}
	return (tab);
}

int		ft_normalize(t_list *tetris)
{
	int c;

	c = 0;
	while (tetris)
	{
		c++;
		ft_up(tetris->content);
		ft_left(tetris->content);
		tetris = tetris->next;
	}
	return (c);
}
