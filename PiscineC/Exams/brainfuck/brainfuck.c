/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 13:00:01 by exam              #+#    #+#             */
/*   Updated: 2018/09/21 13:27:02 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		find_next(char *str)
{
	int		count;
	int		i;

	i = 1;
	count = 0;
	while (str[i])
	{
		if (str[i] == '[')
			count++;
		else if (str[i] == ']')
		{
			if (count == 0)
				return (i);
			else
				count--;
		}
		i++;
	}
	return (0);
}

int		find_previous(char *str)
{
	int		count;
	int		i;

	i = -1;
	count = 0;
	while (str[i])
	{
		if (str[i] == ']')
			count++;
		else if (str[i] == '[')
		{
			if (count == 0)
				return (i);
			else
				count--;
		}
		i--;
	}
	return (0);
}

void	brainfuck(char *str)
{
	char	ptr[2048];
	int		i;
	int		j;

	j = 0;
	while (j < 2048)
		ptr[j++] = '\0';
	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '>')
			j++;
		else if (str[i] == '<')
			j--;
		else if (str[i] == '+')
			ptr[j]++;
		else if (str[i] == '-')
			ptr[j]--;
		else if (str[i] == '.')
			ft_putchar(ptr[j]);
		if (str[i] == '[' && ptr[j] == 0)
			i += find_next(str + i);
		else if (str[i] == ']' && ptr[j] != 0)
			i += find_previous(str + i);
		else
			i++;
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_putchar('\n');
	else
		brainfuck(av[1]);
	return (0);
}
