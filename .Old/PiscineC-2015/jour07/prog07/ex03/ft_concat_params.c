/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 15:50:47 by fklein            #+#    #+#             */
/*   Updated: 2015/10/26 19:12:26 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

char	*add_char(int argc, char **argv, char *tab)
{
	int index;
	int index2;
	int index3;

	index = 1;
	index3 = 0;
	while (index < argc)
	{
		index2 = 0;
		while (argv[index][index2])
		{
			tab[index3] = argv[index][index2];
			index2++;
			index3++;
		}
		tab[index3] = '\n';
		index3++;
		index++;
	}
	tab[index3 - 1] = '\0';
	return (tab);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*tab;
	int		index;
	int		count;

	index = 1;
	count = 0;
	while (index < argc)
	{
		count += ft_strlen(argv[index]);
		index++;
	}
	printf("longueur : %d\n", count);
	tab = malloc(sizeof(char) * count);
	return (add_char(argc, argv, tab));
}

int		main(int argc, char **argv)
{
	printf("chaine : %s", ft_concat_params(argc, argv));
	return (0 * argc);
}
