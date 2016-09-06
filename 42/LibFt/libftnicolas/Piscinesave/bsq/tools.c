/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:28:59 by fklein            #+#    #+#             */
/*   Updated: 2016/04/20 18:29:15 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_strlen(char *s)
{
	int		n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		i;

	cpy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	i = 0;
	while (*(src + i))
	{
		*(cpy + i) = *(src + i);
		i++;
	}
	*(cpy + i) = '\0';
	return (cpy);
}

void	ft_putstr(int fd, char *s)
{
	write(fd, s, ft_strlen(s));
}

char	*ft_space(char *s)
{
	char	*s2;
	char	*cpy;

	if ((s2 = (char *)malloc(sizeof(char) * (1 + 2 * ft_strlen(s)))) == NULL)
		return (NULL);
	cpy = s2;
	while (*s)
	{
		*s2 = *s;
		if (*s2 != '\n')
			*(++s2) = ' ';
		s2++;
		s++;
	}
	*s2 = '\0';
	return (cpy);
}

void	ft_print_map(char **map, int flag)
{
	int		i;

	i = -1;
	while (map[++i])
		ft_putstr(1, (flag) ? ft_space(map[i]) : map[i]);
}
