/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 17:09:25 by fklein            #+#    #+#             */
/*   Updated: 2015/11/01 21:54:21 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	cmp_all(char *mem, int x, int y)
{
	int		i;
	int		what_else;

	i = 0;
	what_else = 0;
	if (ft_strcmp(mem, colle0(x, y)) == 0)
	{
		display("[colle-00]", x, y);
		what_else++;
	}
	if (ft_strcmp(mem, colle1(x, y)) == 0)
		what_else += success1(what_else, x, y);
	if (ft_strcmp(mem, colle2(x, y)) == 0)
		what_else += success2(what_else, x, y);
	if (ft_strcmp(mem, colle3(x, y)) == 0)
		what_else += success3(what_else, x, y);
	if (ft_strcmp(mem, colle4(x, y)) == 0)
		what_else += success4(what_else, x, y);
	if (x > 1 && y > 1 && x == y)
		what_else += successcarre(what_else, x, y);
	if (what_else == 0)
		ft_putstr("aucune");
	ft_putchar('\n');
}

char	*ft_concat_realloc(char *str, char *tmp, int n)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = ft_strlen(str);
	new_str = malloc(sizeof(*str) * (len + n + 1));
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	i = 0;
	while (i < n)
	{
		new_str[i + len] = tmp[i];
		i++;
	}
	return (new_str);
}

char	*ft_pipe_to_string(void)
{
	int		n;
	char	*str;
	char	*tmp;
	int		pas;
	int		i;

	i = 0;
	pas = 1024;
	n = pas;
	tmp = malloc(sizeof(*tmp) * pas);
	str = malloc(0);
	while (n == pas)
	{
		n = read(0, tmp, pas);
		tmp[n] = '\0';
		if (n != 0)
			str = ft_concat_realloc(str, tmp, n + 1);
		i++;
	}
	str[((i - 1) * pas) + n] = '\0';
	return (str);
}

int		main(void)
{
	int		index;
	int		x;
	int		y;
	char	*underwear;

	index = 0;
	x = 0;
	y = 0;
	underwear = ft_pipe_to_string();
	while (*(underwear + index))
	{
		if (*(underwear + index) == '\n')
			y++;
		if (*(underwear + index) != '\n')
			x++;
		index++;
	}
	if (y != 0)
		x = x / y;
	cmp_all(underwear, x, y);
	return (0);
}
