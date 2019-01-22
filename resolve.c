#include "fillit.h"

// Trouve la plus grande raccine carré arrondis au supérieur

int     biggest_sqrt(int nb)
{
	int a;

	a = 2;
	while (a * a < nb)
		a++;
	return (a);
}

// Compte le nnombre d'element dans une liste chainée (aka le nombre de tétromino)

size_t  lstcount(t_list * list)
{
	size_t  a;

	a = 0;
	while (list != NULL)
	{
		list = list->next;
		a++;
	}
	return (a);
}

// Créer le carré dans lequel on va placer les tétromino ( Elle serra lancer plusieur fois en augmentant a chanque fois la valeur size jusqu'a avoir un carré suffisament grand)

t_square  *new_square(int size)
{
	t_square  *square;
	int     a;
	int     b;

	square = (t_square *)ft_memalloc(sizeof(t_square));
	square->size = size;
	square->array = (char **)ft_memalloc(sizeof(char *) * size);
	a = 0;
	while (a < size)
	{
		square->array[a] = ft_strnew(size);
			b = 0;
		while (b < size)
		{
			square->array[a][b] = '.';
			b++;
		}
		a++;
	}
	return (square);
}

void	put(t_tetro *tetro, t_square *square, int c, int d, char z)
{
	int	e;
	int	f;

	e = 0;
	while (e < tetro->l)
	{
		f = 0;
		while (f < tetro->h)
		{
			if (tetro->tetro[f][e] >= 'A' && tetro->tetro[f][e] <= 'Z')
				square->array[d][c] = z;
			f++;
		}
		e++;
	}
}

int		test_put(t_tetro *tetro, t_square *square, int a, int b)
{
	int	c;
	int	d;
	char z;

	c = 0;
	while (c < tetro->l)
	{
		d = 0;
		while (d < tetro->h)
		{
			if ((tetro->tetro[d][c] >= 'A' && tetro->tetro[d][c] <= 'Z') && square->array[b + 1][a + 1] != '.')
				return (0);
			if ((tetro->tetro[d][c] >= 'A' && tetro->tetro[d][c] <= 'Z'))
				z = tetro->tetro[d][c];
			d++;
		}
		c++;
	}
	put(tetro, square, c, d, z);
	return (1);
}


// Fonction qui sera récursive, manque encore la partie qui place les tetro dans la carré, je bosse encore dessus

int		solve(t_square *square, t_list *list)
{
	t_tetro	*tetro;
	int	a;
	int	b;

	if (list == NULL)
		return (1);
	a = 0;
	tetro = (t_tetro *)list->content;
	while (a < square->size - tetro->h + 1)
	{
		b = 0;
		while (b < square->size - tetro->l + 1)
		{
			if (test_put(tetro, square, a, b))
			{
				if (solve(square, list->next))
					return (1);
				else
					put(tetro, square, a, b, '.');
			}
			b++;
		}
		a++;
	}
	return (0);
}

// calcule le plus petit carré possible en fonction du nombre de piece (inutile de commencer avec un carré 2x2 si on sais quand recois 10 tetromino)

t_square  *resolve(t_list *list)
{
	t_square  *square;
	int     size;

	size = biggest_sqrt(lstcount(list) * 4);
	square = new_square(size);
	while (!solve(square, list))
	{
		size++;
		square = new_square(size);
	}
	return (square);
}
