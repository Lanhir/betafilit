/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:47:12 by malibert          #+#    #+#             */
/*   Updated: 2019/01/08 04:58:17 by malibert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		comp(char **tab1, char **tab2)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (*tab1[a] != '\0')
	{
		if (tab1[a][b] != '.' && tab2[a][b] != '.')
			return (0);
		if (tab1[a][b] == '\0')
		{
			b = -1;
			a++;
		}
		b++;
	}
	return (1);
}

int		main()
{
	char **tab1;
	char **tab2;
	char **final;
	int a;
	int b;

	a = 2;
	b = 0;
	while (comp != 1)
	{
		if(!(final = (char**)malloc(sizeof(*final) * a)))
			return(NULL);
		while (b < a)
		{
			if(!(final[b] = (char*)malloc(sizeof(a))))
			{
				free(**final);
				return(NULL);
			}
			b++;
		}
	}
}
