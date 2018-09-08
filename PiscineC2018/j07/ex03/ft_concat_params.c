/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 23:14:07 by flklein           #+#    #+#             */
/*   Updated: 2018/09/06 18:10:04 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len++]);
	return (len - 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		len;
	int		i;
	char	*tab;
	int		j;
	int		c;

	len = 0;
	i = 1;
	while (i < argc)
	{
		len += ft_strlen(argv[i]);
		i++;
	}
	printf("len:%d\n", len);
	if (!(tab = (char*)malloc((len + argc - 2) * sizeof(char))))
		return ("");
	i = 1;
	c = 0;
	while (i < argc)
	{
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			tab[c] = argv[i][j];
			c++;
			j++;
		}
		if (i < argc - 1)
			tab[c++] = '\n';
		i++;
	}
	tab[c] = 0;
	return (tab);
}

int		main(int ac, char **av)
{
	printf("%s", ft_concat_params(ac, av));
}
