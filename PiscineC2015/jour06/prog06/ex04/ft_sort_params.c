/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 21:12:59 by fklein            #+#    #+#             */
/*   Updated: 2015/10/27 23:03:25 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_swap(char **a, char **b)
{
	char *t;

	t = *a;
	*a = *b;
	*b = t;
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
 	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_argv(int argc, char **argv)
{
	int		i;
	int		ct;

	i = 0;
	ct = 1;
	while (ct < argc)
	{
		while (++i < argc - ct)
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
				ft_swap(&argv[i],&argv[i + 1]);
		i = 0;
		ct++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	ft_sort_argv(argc, argv);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
	return (0);
}
